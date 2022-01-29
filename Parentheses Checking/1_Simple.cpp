#include <iostream>
using namespace std;

#define MAXBUFFER 20

struct Node
{
    char data;
    Node *next;
};

//function for checking Stack is empty or not
int isEmpty(Node *head)
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

//simple Stack Push Function
void Push(char bracket, Node **head)
{
    Node *ptr = new Node;

    ptr->data = bracket;
    ptr->next = (*head);
    (*head) = ptr;
}

//simple Stack Pop Function
char Pop(Node **head)
{
    char bracket;

    Node *ptr;
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
    Node *head = NULL;

    for (int i = 0; expression[i]!='\0'; i++)
    {
        if (expression[i] == '(')
            Push(expression[i], &head);

        else if (expression[i] == ')')
        {
            //necessary condition when ')' encounter stack should not be empty
            if (isEmpty(head) == false)
                Pop(&head);
            else
                return 0;
        }
    }

    //and after all ')' occured Stack should be empty
    if (isEmpty(head) == true)
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