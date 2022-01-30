#include <iostream>
#include <stack>
#include<math.h>
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
// function to convert infix expression to postfix expression
string InfixToPostfix(string infix)
{
    //enclosing whole string in parenthesis
    infix.insert(0, "(");
    infix.insert(infix.length(), ")");

    string postfix = "";
    stack<char> st;
    for (int i = 0; i < infix.length(); i++)
    {
        //digit encountered
        if (infix[i] >= '0' && infix[i] <= '9')
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
            while (st.empty() == false && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }

        //operator encountered
        else
        {
            while (st.empty() == false && (precedence(infix[i]) < precedence(st.top())) || precedence(infix[i]) == precedence(st.top()) && associativity(infix[i]) == 'L')
            {
                postfix += st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
    }
    return postfix;
}

float PostfixEvaluator(string postfix)
{
    stack<float> st;
    char currentChar;
    for (int i = 0; i < postfix.length(); i++)
    {
        currentChar = postfix[i];
        //alphabet encountered
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            currentChar = postfix[i] - '0';
            st.push(currentChar);
        }
        //operator encountered
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
        {
            //pop two operands
            float num1 = st.top();
            st.pop();
            float num2 = st.top();
            st.pop();

            //result of operation
            float result = 0;

            //perform operation
            switch (postfix[i])
            {
            case '+':
                result = num2 + num1;
                break;
            case '-':
                result = num2 - num1;
                break;
            case '*':
                result = num2 * num1;
                break;
            case '/':
                result = num2 / num1;
                break;
            case '^':
                result = pow(num2, num1);
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
    cout << "Enter a valid Expression (single digit numbers):";
    getline(cin, expression);
    cout << "\nResult: " << PostfixEvaluator(InfixToPostfix(expression));
}