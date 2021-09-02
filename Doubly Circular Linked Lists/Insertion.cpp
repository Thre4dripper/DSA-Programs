#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

//function for Clockwise Traversing in Doubly Circular Linked list
int TraverseClockwise(node *head)
{
    node *ptr = new node;
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
int TraverseAntiClockwise(node *head)
{
    node *ptr = new node;
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

//function for inserting element at start of Doubly Circular Linked List
void InsertAtStart(int element, node **head)
{
    node *ptr = new node;
    ptr->data = element;

    //when doubly circular linked list is empty , it will create one
    if ((*head)->next == (*head))
    {
        (*head)->next = ptr;
        (*head)->prev = ptr;
        ptr->next = ptr;
        ptr->prev = ptr;
    }
    //when doubly circular linked list has two elememts
    else if ((*head)->next->next == (*head)->next)
    {
        ptr->next = (*head)->next;
        ptr->prev = (*head)->next;
        (*head)->next->next = ptr;
        (*head)->next->prev = ptr;

        (*head)->next = ptr;
        (*head)->prev = ptr;
    }
    //general case for insertion
    else
    {
        ptr->next = (*head)->next;
        ptr->prev = (*head)->next->prev;

        (*head)->next->prev->next = ptr;
        (*head)->next->prev = ptr;

        (*head)->next = ptr;
        (*head)->prev = ptr;
    }
}

//function for inserting element at any index of Doubly Circular Linked List
void InsertAtIndex(int element, int index, node **head, int *size)
{
    //checking for valid indexes
    if (index >= 0 && index <= *size)
    {
        node *ptr = new node;
        ptr->data = element;

        //both cases for zero and last index
        if (index == 0 || index == *size)
        {
            //when doubly circular linked list is empty , it will create one
            if ((*head)->next == (*head))
            {
                (*head)->next = ptr;
                (*head)->prev = ptr;
                ptr->next = ptr;
                ptr->prev = ptr;
            }
            //when doubly circular linked list has two elememts
            else if ((*head)->next->next == (*head)->next)
            {
                ptr->next = (*head)->next;
                ptr->prev = (*head)->next;
                (*head)->next->next = ptr;
                (*head)->next->prev = ptr;

                //head will point to ptr for zero index
                if (index == 0)
                {
                    (*head)->next = ptr;
                    (*head)->prev = ptr;
                }
            }
            else
            {
                ptr->next = (*head)->next;
                ptr->prev = (*head)->next->prev;

                (*head)->next->prev->next = ptr;
                (*head)->next->prev = ptr;

                //head will point to ptr for zero index
                if (index == 0)
                {
                    (*head)->next = ptr;
                    (*head)->prev = ptr;
                }
            }
        }
        //general case for indexes between 0 and last
        else
        {
            node *p = new node;
            p = (*head)->next;

            for (int i = 0; i < index - 1; i++)
                p = p->next;

            ptr->next = p->next;
            ptr->prev = p;

            p->next->prev = ptr;
            p->next = ptr;
        }
        (*size)++;
    }
    else
        cout << "Invalid Index" << endl;
}

//function for inserting element at end of Doubly Circular Linked List
void InsertAtEnd(int element, node **head)
{
    node *ptr = new node;
    ptr->data = element;

    //when doubly circular linked list is empty , it will create one
    if ((*head)->next == (*head))
    {
        (*head)->next = ptr;
        (*head)->prev = ptr;
        ptr->next = ptr;
        ptr->prev = ptr;
    }
    //when doubly circular linked list has two elememts
    else if ((*head)->next->next == (*head)->next)
    {
        ptr->next = (*head)->next;
        ptr->prev = (*head)->next;
        (*head)->next->next = ptr;
        (*head)->next->prev = ptr;
    }
    //general case for indexes between 0 and last
    else
    {
        ptr->next = (*head)->next;
        ptr->prev = (*head)->next->prev;

        (*head)->next->prev->next = ptr;
        (*head)->next->prev = ptr;
    }
}

int main()
{
    system("cls");
    node *head = new node;
    head->next = head;
    head->prev = head;

    int size;

    size = TraverseClockwise(head);
    InsertAtIndex(10, 0, &head, &size);
    InsertAtIndex(20, 0, &head, &size);
    InsertAtIndex(30, 2, &head, &size);

    size = TraverseClockwise(head);
}