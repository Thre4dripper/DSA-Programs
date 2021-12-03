#include <iostream>
using namespace std;

#define MAX_BUFFER 100
struct node
{
    char data;
    node *next;
};

//function for checking Stack is empty or not
bool isEmpty(node *head)
{

    cout << endl;
    bool isempty = true;
    while (head != NULL)
    {
        isempty = false;
        head = head->next;
    }

    return isempty;
}

//function for checking Top element of Stack
bool isOntop(char bracket, node *head)
{
    if (head!=NULL && bracket == head->data)
        return true;
    else
        return false;
}

//simple Stack Push Function
void Push(char bracket, node **head)
{
    node *ptr = new node;

    ptr->data = bracket;
    ptr->next = (*head);
    (*head) = ptr;
}

//simple Stack Pop Function
char Pop(node **head)
{
    char bracket;

    node *ptr;
    ptr = (*head);

    if (ptr == NULL)
        cout << "Stack Empty" << endl;
    else
    {
        (*head) = (*head)->next;
        bracket = ptr->data;
    }
    delete ptr;

    return bracket;
}

//main function for checcking expression validity
int checkValidity(char expression[])
{
    node *head = NULL;

    for (int i = 0;expression[i]!='\0'; i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
            Push(expression[i], &head);

        else if (expression[i] == ')')
        {
            //condition when ')' stack should not be empty and  '(' must be on Top
            if (isEmpty(head) == false && isOntop('(',head)==true)
                Pop(&head);
            else
                return 0;
        }
        else if (expression[i] == '}')
        {
            //condition when '}' stack should not be empty and  '{' must be on Top
            if (isEmpty(head) == false && isOntop('{',head)==true)
                Pop(&head);
            else
                return 0;
        }
        else if (expression[i] == ']')
        {
            //condition when ']' stack should not be empty and  '[' must be on Top
            if (isEmpty(head) == false && isOntop('[',head)==true)
                Pop(&head);
            else
                return 0;
        }
    }
    //ABOVE CODE CAN BE SIMPLIFIED TO USE LESS 'IF ELSE' STATEMENTS BUT THEN 
    //CODE WOULD BE MUCH MORE COMPLEX TO UNDERSTAND

    //and after all ')' occured Stack should be empty
    if (isEmpty(head) == true)
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