#include <iostream>
#include <stack>
using namespace std;

#define MAXBUFFER 100

//main function for checcking expression validity
int checkValidity(char expression[])
{
    stack<char> st;

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(')
            st.push(expression[i]);

        else if (expression[i] == ')')
        {
            //necessary condition when ')' encounter stack should not be empty
            if (st.empty() == false)
                st.pop();
            else
                return 0;
        }
    }

    //and after all ')' occured Stack should be empty
    if (st.empty() == true)
        return 1;
    else
        return 0;
}

int main()
{
    system("cls");

    char expression[MAXBUFFER];

    fgets(expression, MAXBUFFER, stdin);

    cout << endl
         << checkValidity(expression);
}