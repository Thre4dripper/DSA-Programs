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

    if (head != NULL && bracket == head->data)
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
bool checkValidity(char expression[])
{
    node *head = NULL;

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(')
        {
            //   '(' can overlap all three brackets and can fill empty stack
            if (isOntop('(', head) == true || isOntop('{', head) == true || isOntop('[', head) == true || isEmpty(head) == true)
                Push(expression[i], &head);
            else
                return false;
        }
        else if (expression[i] == '{')
        {
            //   '{' can overlap only itself and '(' and can fill empty stack
            if (isOntop('{', head) == true || isOntop('[', head) == true || isEmpty(head) == true)
                Push(expression[i], &head);
            else
                return false;
        }
        else if (expression[i] == '[')
        {
             //   '[' can overlap only itself and can fill empty stack
            if (isOntop('[', head) == true || isEmpty(head) == true)
                Push(expression[i], &head);
            else
                return false;
        }
        else if (expression[i] == ')')
        {
            //condition when ')' stack should not be empty and  '(' must be on Top
            if (isEmpty(head) == false && isOntop('(', head) == true)
                Pop(&head);
            else
                return false;
        }
        else if (expression[i] == '}')
        {
            //condition when '}' stack should not be empty and  '{' must be on Top
            if (isEmpty(head) == false && isOntop('{', head) == true)
                Pop(&head);
            else
                return false;
        }
        else if (expression[i] == ']')
        {
            //condition when ']' stack should not be empty and  '[' must be on Top
            if (isEmpty(head) == false && isOntop('[', head) == true)
                Pop(&head);
            else
                return false;
        }
    }
    //ABOVE CODE CAN BE SIMPLIFIED TO USE LESS 'IF ELSE' STATEMENTS BUT THEN
    //CODE WOULD BE MUCH MORE COMPLEX TO UNDERSTAND

    //and after all ')' occured Stack should be empty
    if (isEmpty(head) == true)
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