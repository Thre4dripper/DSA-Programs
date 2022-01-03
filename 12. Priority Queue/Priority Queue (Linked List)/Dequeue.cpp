#include <iostream>
using namespace std;

struct node
{
    string name;
    int priority;
    node *next;
};

//function for deleting elements from priority queue
node dequeue(node **front, node **rear)
{
    node element = {"null", -1};
    if (*front != NULL)
    {
        node *ptr = *front;
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

    node *first = new node;
    node *second = new node;
    node *third = new node;
    node *forth = new node;
    node *fifth = new node;

    node *front = first;
    node *rear = fifth;

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