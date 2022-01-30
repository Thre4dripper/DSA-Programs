#include <iostream>
#include <stack>
using namespace std;

// function to calculate precedence of a operator
int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else
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
        //alphabet encountered
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
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
            while (st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }

        //operator encountered
        else
        {
            while (precedence(infix[i]) <= precedence(st.top()))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
    }
    return postfix;
}

int main()
{
    system("cls");

    string expression;
    cout << "Enter a valid Expression:";
    getline(cin, expression);
    cout << "Postfix Expression: " << InfixToPostfix(expression) << endl;
}