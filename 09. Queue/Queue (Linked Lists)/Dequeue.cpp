#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

//for traverse and display all nodes of linked list
int display(node *head)
{
    int size = 0;
    cout << endl;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
        size++;
    }
    return size;
}

int dequeue(node **front, node **rear)
{
    int element = NULL;
    if (*front != NULL)
    {
        node *ptr;
        ptr = *front;
        element = (*front)->data;
        *front = (*front)->next;

        delete ptr;
    }
    else
        cout << "Queue Underflow" << endl;
    return element;
}

int main()
{
    system("cls");

    int size;
    node *first = new node;
    node *second = new node;
    node *third = new node;
    node *forth = new node;
    node *fifth = new node;

    node *front = first;
    node *rear = fifth;

    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = forth;

    forth->data = 40;
    forth->next = fifth;

    fifth->data = 50;
    fifth->next = NULL;

    size = display(front);
    cout << endl
         << dequeue(&front, &rear);
    cout << endl
         << dequeue(&front, &rear);
    cout << endl
         << dequeue(&front, &rear);
}