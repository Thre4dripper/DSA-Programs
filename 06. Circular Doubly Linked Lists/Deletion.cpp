#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

//function for Clockwise Traversing in Doubly Circular Linked list
int TraverseClockwise(Node *head)
{
    Node *ptr = new Node;
    ptr = head;

    int size = 0;

    cout << "\nDoubly Circular Linked list->";
    //Condition for Empty doubly circular linked list
    if (ptr->next != ptr)
    {
        ptr = ptr->next;
        //at least one time loop must run, cause starting and ending condition is same
        do
        {
            size++;
            cout << ptr->data << " ";
            ptr = ptr->next;

        } while (ptr != head->next);
    }

    else
        cout << "Empty" << endl;

    return size;
}

//function for AntiClockwise Traversing in Doubly Circular Linked list
int TraverseAntiClockwise(Node *head)
{
    Node *ptr = new Node;
    ptr = head;

    int size = 0;

    cout << "\nDoubly Circular Linked list->";
    //Condition for Empty doubly circular linked list
    if (ptr->prev != ptr)
    {
        ptr = ptr->prev;
        //at least one time loop must run, cause starting and ending condition is same
        do
        {
            size++;
            cout << ptr->data << " ";
            ptr = ptr->prev;

        } while (ptr != head->prev);
    }

    else
        cout << "Empty" << endl;

    return size;
}

//function for deleting element from Start of Doubly Circular Linked List
int deleteFromStart(Node **head, int *size)
{
    //removing element
    int element;

    //condition for empty doubly circular linked list
    if ((*head)->next == (*head))
        cout << "Empty Doubly Circular Linked List" << endl;
    else
    {
        Node *ptr;
        ptr = (*head)->next;
        element = ptr->data;

        //when only one node in doubly circular linked list
        if ((*head)->next->next == (*head)->next)
        {
            (*head)->next = (*head);
            (*head)->prev = (*head);
        }
        //when two nodes in doubly circular linked list
        else if ((*head)->next->next->next == (*head)->next)
        {
            (*head)->next->next->next = (*head);
            (*head)->next = (*head)->next->next;
        }
        //general case for more than two nodes
        else
        {
            (*head)->next->next->prev = (*head)->next->prev;
            (*head)->next->prev->next = (*head)->next->next;
            (*head)->next = (*head)->next->next;
            (*head)->prev = (*head)->next->next;
        }

        delete ptr;
        (*size)--;
    }

    return element;
}

//function for deleting element from and Index of Doubly Circular Linked List
int deleteFromIndex(int index, Node **head, int *size)
{
    //removing element
    int element;

    //condition for empty doubly circular linked list
    if (index >= 0 && index < *size)
    {
        Node *ptr;
        ptr = (*head)->next;

        //condition for '0' index
        if (index == 0)
        {
            element = ptr->data;

            //when only one node in doubly circular linked list
            if ((*head)->next->next == (*head)->next)
            {
                (*head)->next = (*head);
                (*head)->prev = (*head);
            }
            //when two nodes in doubly circular linked list
            else if ((*head)->next->next->next == (*head)->next)
            {
                (*head)->next->next->next = (*head);
                (*head)->next = (*head)->next->next;
            }
            //general case for more than two nodes
            else
            {
                (*head)->next->next->prev = (*head)->next->prev;
                (*head)->next->prev->next = (*head)->next->next;
                (*head)->next = (*head)->next->next;
                (*head)->prev = (*head)->next->next;
            }
        }
        //condition for last index
        else if (index == *size - 1)
        {
            //when only one node in doubly circular linked list
            if ((*head)->next->next == (*head)->next)
            {
                element = ptr->data;

                (*head)->next = (*head);
                (*head)->prev = (*head);
            }
            //when two nodes in doubly circular linked list
            else if ((*head)->next->next->next == (*head)->next)
            {
                ptr = ptr->prev;
                element = ptr->data;

                (*head)->next->next = (*head)->next;
                (*head)->next->prev = (*head)->next;
            }
            //general case for more than two nodes
            else
            {
                ptr = ptr->prev;
                element = ptr->data;

                (*head)->next->prev->prev->next = (*head)->next;
                (*head)->next->prev = (*head)->next->prev->prev;
            }
        }
        //condition for indexes between 0 and last
        else
        {
            Node *p;
            p = (*head)->next;

            //condition for indexes in first half of doubly circular linked list
            if (index <= (*size) / 2)
            {
                for (int i = 0; i < index - 1; i++)
                    p = p->next;

                ptr = p->next;
                element = ptr->data;

                p->next->next->prev = p;
                p->next = p->next->next;
            }
            //condition for indexes in second half of doubly circular linked list
            else
            {

                for (int i = *size; i > index + 1; i--)
                    p = p->prev;

                ptr = p->prev;
                element = ptr->data;

                p->prev->prev->next = p;
                p->prev = p->prev->prev;
            }
        }

        delete ptr;
        (*size)--;
    }
    else
        cout << "Invalid Index" << endl;

    return element;
}

//function for deleting element from End of Doubly Circular Linked List
int deleteFromEnd(Node **head, int *size)
{
    //removing element
    int element;

    //condition for empty doubly circular linked list
    if ((*head)->next == (*head))
        cout << "Empty Doubly Circular Linked List" << endl;
    else
    {
        Node *ptr;
        ptr = (*head)->next;

        //when only one node in doubly circular linked list
        if ((*head)->next->next == (*head)->next)
        {
            element = ptr->data;

            (*head)->next = (*head);
            (*head)->prev = (*head);
        }
        //when two nodes in doubly circular linked list
        else if ((*head)->next->next->next == (*head)->next)
        {
            ptr = ptr->prev;
            element = ptr->data;

            (*head)->next->next = (*head)->next;
            (*head)->next->prev = (*head)->next;
        }
        //general case for more than two nodes
        else
        {
            ptr = ptr->prev;
            element = ptr->data;

            (*head)->next->prev->prev->next = (*head)->next;
            (*head)->next->prev = (*head)->next->prev->prev;
        }

        delete ptr;
        (*size)--;
    }

    return element;
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

    /* fisrt node will always be printed in both cloackwise and anticlockwise direction
    * cause iterator will enter into Doubly Circular Linked list by first node
    */
    size = TraverseClockwise(head);

    cout << endl
         << deleteFromIndex(3, &head, &size);
    cout << endl
         << deleteFromIndex(3, &head, &size);
    cout << endl
         << deleteFromIndex(0, &head, &size);

    size = TraverseClockwise(head);
}