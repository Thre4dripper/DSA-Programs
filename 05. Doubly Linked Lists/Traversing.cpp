#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

//function for Traverse Doubly Linked List forward
void TraverseForward(Node *head)
{

    cout << endl;

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

//function for Traverse Doubly Linked List backward
void TraverseBackward(Node *tail)
{

    cout << endl;

    while (tail != NULL)
    {
        cout << tail->data << " ";
        tail = tail->prev;
    }
}

int main()
{
    system("cls");
    Node *head;
    Node *tail;

    Node *first = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *forth = new Node;
    Node *fifth = new Node;

    int size;

    first->data = 10;
    first->prev = NULL;
    first->next = second;

    second->data = 20;
    second->prev = first;
    second->next = third;

    third->data = 30;
    third->prev = second;
    third->next = forth;

    forth->data = 40;
    forth->prev = third;
    forth->next = fifth;

    fifth->data = 50;
    fifth->prev = forth;
    fifth->next = NULL;

    head = first;
    tail = fifth;

    TraverseForward(head);
    TraverseBackward(fifth);
}