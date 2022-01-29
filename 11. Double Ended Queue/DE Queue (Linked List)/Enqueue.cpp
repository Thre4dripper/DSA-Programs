#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int display(Node *front)
{
    int size = 0;
    cout << endl;
    while (front != NULL)
    {
        cout << front->data << " ";
        front = front->next;
        size++;
    }

    return size;
}

//function to insert element at start
void enqueueStart(int element, Node **front, Node **rear)
{
    Node *ptr = new Node;

    ptr->data = element;
    ptr->next = NULL;
    if (*front == NULL)
        *front = *rear = ptr;

    else
    {
        ptr->next = *front;
        (*front) = ptr;
    }
}

//function to insert element at end
void enqueueEnd(int element, Node **front, Node **rear)
{
    Node *ptr = new Node;

    ptr->data = element;
    ptr->next = NULL;
    if (*front == NULL)
        *front = *rear = ptr;

    else
    {
        (*rear)->next = ptr;
        *rear = ptr;
    }
}

int main()
{
    system("cls");
    Node *front = NULL;
    Node *rear = NULL;

    display(front);
    enqueueEnd(10, &front, &rear);
    enqueueEnd(20, &front, &rear);
    enqueueEnd(30, &front, &rear);
    enqueueStart(40, &front, &rear);
    enqueueStart(50, &front, &rear);

    display(front);
}