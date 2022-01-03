#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

int display(node *front)
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
void enqueueStart(int element, node **front, node **rear)
{
    node *ptr = new node;

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
void enqueueEnd(int element, node **front, node **rear)
{
    node *ptr = new node;

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
    node *front = NULL;
    node *rear = NULL;

    display(front);
    enqueueEnd(10, &front, &rear);
    enqueueEnd(20, &front, &rear);
    enqueueEnd(30, &front, &rear);
    enqueueStart(40, &front, &rear);
    enqueueStart(50, &front, &rear);

    display(front);
}