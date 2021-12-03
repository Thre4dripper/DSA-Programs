#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

//function for Traverse Doubly Linked List forward
void TraverseForward(node *head)
{

    cout << endl;

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

//function for Traverse Doubly Linked List backward
void TraverseBackward(node *tail)
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
    node *head;
    node *tail;

    node *first = new node;
    node *second = new node;
    node *third = new node;
    node *forth = new node;
    node *fifth = new node;

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