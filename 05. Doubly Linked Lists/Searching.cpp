#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

//function for Searcing an element in Doubly Linked List
int search(int element, Node *head, Node *tail, int size)
{
    bool found = false;
    Node *ptr;
    ptr = head;

    while (ptr != NULL)
    {
        if (ptr->data == element)
        {
            found = true;
            break;
        }
        else
            ptr = ptr->next;
    }

    return found;
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

    int size = 5;

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

    cout << endl
         << search(41, head, tail, size);
    cout << endl
         << search(30, head, tail, size);
}