#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

// function to calculate precedence of a operator
int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return 0;
}

// function to calculate associativity of a operator
char associativity(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        return 'L';
    case '^':
        return 'R';
    }
    return 0;
}

//function to insert saperator of multi digit number
string MultiDigitOptimizer(string infix)
{
    for (int i = 1; i < infix.length(); i++)
    {
        if ((infix[i - 1] >= '0' && infix[i - 1] <= '9') && infix[i] != '.' && !(infix[i] >= '0' && infix[i] <= '9'))
        {
            infix.insert(i, " ");
        }
    }
    return infix;
}

// function to convert infix expression to postfix expression
string InfixToPostfix(string infix)
{
    //enclosing whole string in parentheses
    infix.insert(0, "(");
    infix.insert(infix.length(), ")");

    //optimizing expression for multi digit number
    infix = MultiDigitOptimizer(infix);

    string postfix;
    stack<char> st;
    for (int i = 0; i < infix.length(); i++)
    {
        //digit or point encountered with saperator
        if ((infix[i] >= '0' && infix[i] <= '9') || infix[i] == '.' || infix[i] == ' ')
        {
            postfix += infix[i];
        }

        //opening bracket
        else if (infix[i] == '(')
        {
            st.push(infix[i]);
        }

        //closing bracket
        else if (infix[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }

        //operator encountered
        else
        {
            while (!st.empty() && (precedence(infix[i]) < precedence(st.top())) ||
                   precedence(infix[i]) == precedence(st.top()) && associativity(infix[i]) == 'L')
            {
                postfix += st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
    }

    return postfix;
}

//function to evaluate postfix expression
string PostfixEvaluator(string postfix)
{
    //getting postfix expression
    postfix = InfixToPostfix(postfix);

    //creating stack to store operands
    stack<string> st;
    int flag = 0;
    char currentChar;

    //iterating through postfix expression
    for (int i = 0; i < postfix.length(); i++)
    {
        currentChar = postfix[i];

        //digit or point encountered
        if ((currentChar >= '0' && currentChar <= '9') || currentChar == '.')
        {
            //flag for detecting multiple digits
            if (flag == 0)
            {
                flag = 1;
                if (currentChar == '.')
                    st.push(".");
                else
                    st.push(to_string(currentChar - '0'));
            }
            else
            {
                string number = st.top();
                st.pop();

                //appending current digit to number for multiple digits
                if (currentChar == '.')
                    number.append(".");
                else
                    number.append(to_string(currentChar - '0'));
                st.push(number);
            }
        }

        //resetting flag for multiple digits
        else if (currentChar == ' ')
            flag = 0;

        //operands encountered
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' ||
                 postfix[i] == '^')
        {
            string num1 = st.top();
            st.pop();
            string num2 = st.top();
            st.pop();

            string result;

            //calculating result
            switch (currentChar)
            {
            case '+':
                result = to_string(stof(num1) + stof(num2));
                break;

            case '-':
                result = to_string(stof(num2) - stof(num1));
                break;

            case '*':
                result = to_string(stof(num1) * stof(num2));
                break;

            case '/':
                result = to_string(stof(num2) / stof(num1));
                break;

            case '^':
                result = to_string(pow(stof(num2), stof(num1)));
                break;
            }
            st.push(result);
        }
    }

    return st.top();
}

int main()
{
    system("cls");

    string expression;
    cout << "Enter a valid Expression (multiple digits with float values allowed):";
    getline(cin, expression);
    cout << "\nResult: " << PostfixEvaluator(expression);
}