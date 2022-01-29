#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

//for traverse and display all nodes of linked list
int display(Node *head)
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

int dequeue(Node **front, Node **rear)
{
    int element = NULL;
    if (*front != NULL)
    {
        Node *ptr;
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
    Node *first = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *forth = new Node;
    Node *fifth = new Node;

    Node *front = first;
    Node *rear = fifth;

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