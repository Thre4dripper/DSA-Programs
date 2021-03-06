#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

//fucntion for travering circular linked list
int traverse(Node *head)
{
    //function also used to calculate size of circular linked list
    int size = 0;

    Node *ptr = new Node;
    ptr = head;
    cout << endl
         << "Circular Linked List->";

    //checking of empty circular linked list
    if (ptr->next != ptr)
    {
        //then advancing pointer to the circular linked list
        ptr = head->next;

        //at least one time loop will run (cause condition also ends on start)
        do
        {
            size++;
            cout << ptr->data << " ";
            ptr = ptr->next;

        } while (ptr != head->next);
        //it will loop whole circular linked list to end at start
    }
    else
        cout << "Empty" << endl;

    return size;
}

//function to delete element from start of circulat linked list
int deleteFromStart(Node **head, int *size)
{
    int element;

    //case for empty circular linked list
    if ((*head)->next == *head)
        cout << "Empty Circular Linked List" << endl;
    else
    {
        Node *ptr = new Node;

        ptr = (*head)->next;
        element = ptr->data;

        //two cases for filled and size 1 circular linked list
        if (*size != 1)
        {
            Node *p = new Node;
            p = (*head)->next;

            while (p->next != (*head)->next)
            {
                p = p->next;
            }

            (*head)->next = ptr->next;
            p->next = ptr->next;
        }
        else
        {
            (*head)->next = *head;
        }

        delete ptr;
        (*size)--;
    }

    return element;
}

//function to delete element from any index in circular linked list
int deleteFromIndex(Node **head, int index, int *size)
{
    int element;

    //valid index case
    if (index < *size && index >= 0)
    {
        Node *ptr = new Node;
        Node *p = new Node;
        p = ptr = (*head)->next;

        //two case for filled and size 1 circular linked list
        if (index == 0)
        {
            if (*size != 1)
            {
                element = ptr->data;

                while (p->next != (*head)->next)
                {
                    p = p->next;
                }
                (*head)->next = ptr->next;
                p->next = ptr->next;

                delete ptr;
            }
            else
            {
                element = ptr->data;
                (*head)->next = *head;

                delete ptr;
            }
        }
        //index other than '0' case
        else
        {
            ptr = p->next;
            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
                ptr = p->next;
            }

            element = ptr->data;
            p->next = ptr->next;

            delete ptr;
        }
        (*size)--;
    }
    else
        cout << "Invalid Index" << endl;
    return element;
}

//function to delete element from End in circular linked list
int deleteFromEnd(Node **head, int *size)
{
    int element;

    //case for empty circular linked list
    if ((*head)->next == *head)
        cout << "Empty Circular Linked List" << endl;
    else
    {
        Node *ptr = new Node;
        ptr = (*head)->next;

        //two cases for filled and size 1 circular linked list
        if (*size != 1)
        {
            Node *p = new Node;
            p = (*head)->next;

            while (ptr->next != (*head)->next)
            {
                p = p->next;
                ptr = p->next;
            }

            element = ptr->data;
            p->next = (*head)->next;
        }
        else
        {
            element = ptr->data;

            (*head)->next = *head;
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
    Node *second = new Node;
    Node *third = new Node;
    Node *forth = new Node;
    Node *fifth = new Node;

    int size;

    head->next = head;

    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = forth;

    forth->data = 40;
    forth->next = fifth;

    fifth->data = 50;
    fifth->next = second;

    size = traverse(head);

    cout << endl
         << deleteFromIndex(&head, 3, &size);

    cout << endl
         << deleteFromIndex(&head, 0, &size);

    traverse(head);
}