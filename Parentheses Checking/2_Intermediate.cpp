#include <iostream>
#include <stack>
using namespace std;

#define MAX_BUFFER 100

//main function for checcking expression validity
int checkValidity(char expression[])
{
    stack<char> st;

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
            st.push(expression[i]);

        else if (expression[i] == ')')
        {
            //condition when ')' stack should not be empty and  '(' must be on Top
            if (st.empty() == false && st.top() == '(')
                st.pop();
            else
                return 0;
        }
        else if (expression[i] == '}')
        {
            //condition when '}' stack should not be empty and  '{' must be on Top
            if (st.empty() == false && st.top() == '{')
                st.pop();
            else
                return 0;
        }
        else if (expression[i] == ']')
        {
            //condition when ']' stack should not be empty and  '[' must be on Top
            if (st.empty() == false && st.top() == '[')
                st.pop();
            else
                return 0;
        }
    }
    //ABOVE CODE CAN BE SIMPLIFIED TO USE LESS 'IF ELSE' STATEMENTS BUT THEN
    //CODE WOULD BE MUCH MORE COMPLEX TO UNDERSTAND

    //and after all ')' occured Stack should be empty
    if (st.empty() == true)
        return 1;
    else
        return 0;
}

int main()
{
    system("cls");

    char expression[MAX_BUFFER];

    fgets(expression, MAX_BUFFER, stdin);

    cout << endl
         << checkValidity(expression);
}