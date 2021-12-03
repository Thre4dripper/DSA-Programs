#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

//function for Clockwise Traversing in Doubly Circular Linked list
void TraverseClockwise(node *head)
{
    node *ptr = new node;

    ptr = head;

    cout << "\nDoubly Circular Linked list->";
    //Condition for Empty doubly circular linked list
    if (ptr->next != ptr)
    {
        ptr = ptr->next;
        //at least one time loop must run, cause starting and ending condition is same
        do
        {
            cout << ptr->data << " ";
            ptr = ptr->next;

        } while (ptr != head->next);
    }

    else
        cout << "Empty" << endl;
}

//function for AntiClockwise Traversing in Doubly Circular Linked list
void TraverseAntiClockwise(node *head)
{
    node *ptr = new node;

    ptr = head;

    cout << "\nDoubly Circular Linked list->";
    //Condition for Empty doubly circular linked list
    if (ptr->prev != ptr)
    {
        ptr = ptr->prev;
        //at least one time loop must run, cause starting and ending condition is same
        do
        {
            cout << ptr->data << " ";
            ptr = ptr->prev;
        } while (ptr != head->prev);
    }

    else
        cout << "Empty" << endl;
}

int main()
{
    system("cls");
    node *head = new node;
    head->next = head;
    head->prev = head;

    node *first = new node;
    node *second = new node;
    node *third = new node;
    node *forth = new node;
    node *fifth = new node;

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

    /* fisrt node will always be printed in both cloackwise and anticlockwise direction
    * cause iterator will enter into Doubly Circular Linked list by first node
    */
    TraverseClockwise(head);
    TraverseAntiClockwise(head);
}