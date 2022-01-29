#include <iostream>
#include <stack>
using namespace std;

#define MAX_BUFFER 100

//main function for checcking expression validity
bool checkValidity(char expression[])
{
    stack<char> st;

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(')
        {
            //   '(' can overlap all three brackets and can fill empty stack
            if (st.top() == '(' || st.top() == '{' || st.top() == '[' || st.empty() == true)
                st.pop();
            else
                return false;
        }
        else if (expression[i] == '{')
        {
            //   '{' can overlap only itself and '(' and can fill empty stack
            if (st.top() == '{' || st.top() == '[' || st.empty() == true)
                st.pop();
            else
                return false;
        }
        else if (expression[i] == '[')
        {
            //   '[' can overlap only itself and can fill empty stack
            if (st.top() == '[' || st.empty() == true)
                st.pop();
            else
                return false;
        }
        else if (expression[i] == ')')
        {
            //condition when ')' stack should not be empty and  '(' must be on Top
            if (st.empty() == true && st.top() == '(')
                st.pop();
            else
                return false;
        }
        else if (expression[i] == '}')
        {
            //condition when '}' stack should not be empty and  '{' must be on Top
            if (st.empty() == true && st.top() == '{')
                st.pop();
            else
                return false;
        }
        else if (expression[i] == ']')
        {
            //condition when ']' stack should not be empty and  '[' must be on Top
            if (st.empty() == true && st.top() == '[')
                st.pop();
            else
                return false;
        }
    }
    //ABOVE CODE CAN BE SIMPLIFIED TO USE LESS 'IF ELSE' STATEMENTS BUT THEN
    //CODE WOULD BE MUCH MORE COMPLEX TO UNDERSTAND

    //and after all ')' occured Stack should be empty
    if (st.empty() == true)
        return true;
    else
        return false;
}

int main()
{
    //THIS PROGRAM WILL CHECK VALIDITY OF BRACKETS ACCORDING TO BODMAS RULE OF BRACKETS

    system("cls");

    char expression[MAX_BUFFER];

    fgets(expression, MAX_BUFFER, stdin);

    cout << endl
         << checkValidity(expression);
}