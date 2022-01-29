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

//function to delete element from start
int dequeueStart(Node **front, Node **rear)
{
    int element = 0;
    if (*front != NULL)
    {
        Node *ptr = *front;
        element = (*front)->data;
        *front = (*front)->next;

        if (*front == NULL)
            *rear = NULL;

        delete ptr;
    }
    else
        cout << "Queue Underflow" << endl;
    return element;
}

//function to delete element from end
int dequeueEnd(Node **front, Node **rear)
{
    int element = 0;

    if (*front != NULL)
    {
        //only one node is left, below logic doesn't work on this
        //otherwise u have to use two sliding pointers
        if ((*front)->next == NULL)
            return dequeueStart(front, rear);

        Node *ptr = *front;

        //reching second last node
        while (ptr->next->next != NULL)
            ptr = ptr->next;

        element = ptr->next->data;

        delete ptr->next;
        ptr->next = NULL;
        *rear = ptr;
    }
    else
        cout << "Queue Underflow" << endl;
    return element;
}

int main()
{
    system("cls");

    int size;
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *forth = new Node;
    Node *fifth = new Node;

    Node *front = head;
    Node *rear = fifth;

    head->data = 10;
    head->next = second;

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
         << dequeueStart(&front, &rear);
    cout << endl
         << dequeueStart(&front, &rear);
    cout << endl
         << dequeueStart(&front, &rear);
    cout << endl
         << dequeueEnd(&front, &rear);
    cout << endl
         << dequeueEnd(&front, &rear);
    cout << endl
         << dequeueEnd(&front, &rear);
}