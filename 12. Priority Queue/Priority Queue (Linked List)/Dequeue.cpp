#include <iostream>
using namespace std;

struct Node
{
    string name;
    int priority;
    Node *next;
};

//function for deleting elements from priority queue
Node dequeue(Node **front, Node **rear)
{
    Node element = {"null", -1};
    if (*front != NULL)
    {
        Node *ptr = *front;
        element = *(*front);
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

    Node *first = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *forth = new Node;
    Node *fifth = new Node;

    Node *front = first;
    Node *rear = fifth;

    first->name = "p2";
    first->priority = 5;
    first->next = second;

    second->name = "p1";
    second->priority = 4;
    second->next = third;

    third->name = "p5";
    third->priority = 3;
    third->next = forth;

    forth->name = "p3";
    forth->priority = 2;
    forth->next = fifth;

    fifth->name = "p4";
    fifth->priority = 1;
    fifth->next = NULL;

    //assuming larger number has higher priority
    cout << endl
         << dequeue(&front, &rear).name;
    cout << endl
         << dequeue(&front, &rear).name;
    cout << endl
         << dequeue(&front, &rear).name;
}