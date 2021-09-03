#include <iostream>
using namespace std;

struct node
{
    char data;
    node *next;
};

//function for checking Stack is empty or not
int isEmpty(node *head)
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
int checkValidity(char expression[], int n)
{
    node *head = NULL;

    for (int i = 0; i < n; i++)
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

    char expression[20];

    fgets(expression, 20, stdin);

    cout << endl
         << checkValidity(expression, 20);
}