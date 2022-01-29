#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

//function for searcing element in Doubly Circular Linked List
int search(int element, Node *head)
{
    int found = false;

    Node *ptr;
    ptr = head->next;

    //checking for empty doubly circular linked list
    if (head->next != head)
        do
        {
            if (ptr->data == element)
            {
                found = true;
                break;
            }
            else
                ptr = ptr->next;

        } while (ptr != head->next);
    else
        cout << "Empty Doubly Circular Linked List" << endl;

    return found;
}

int main()
{
    system("cls");
    Node *head = new Node;
    head->next = head;
    head->prev = head;

    Node *first = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *forth = new Node;
    Node *fifth = new Node;

    int size;

    first->data = 10;
    first->next = second;
    first->prev = fifth;

    second->data = 20;
    second->next = third;
    second->prev = first;

    third->data = 30;
    third->next = forth;
    third->prev = second;

    forth->data = 40;
    forth->next = fifth;
    forth->prev = third;

    fifth->data = 50;
    fifth->next = first;
    fifth->prev = forth;

    head->next = first;
    head->prev = first;

    cout << endl
         << search(20, head);

    cout << endl
         << search(60, head);
}