#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

//function for Traverse Doubly Linked List forward
int TraverseForward(Node *head)
{
    int size = 0;
    cout << endl;

    while (head != NULL)
    {
        size++;
        cout << head->data << " ";
        head = head->next;
    }

    return size;
}

//function for Traverse Doubly Linked List borward
int TraverseBackward(Node *tail)
{
    int size = 0;
    cout << endl;

    while (tail != NULL)
    {
        size++;
        cout << tail->data << " ";
        tail = tail->prev;
    }

    return size;
}

//function for insert an element at start of Doubly Linked List
void insertAtStart(int element, Node **head, Node **tail)
{
    Node *ptr = new Node;
    ptr->data = element;

    //checking for empty linked list
    if ((*head) == NULL)
    {
        ptr->next = NULL;
        ptr->prev = NULL;
        (*head) = (*tail) = ptr;
    }
    else
    {
        ptr->next = (*head);
        (*head)->prev = ptr;
        (*head) = ptr;
        ptr->prev = NULL;
    }
}

//function for insert an index at start of Doubly Linked List
void insertAtIndex(int element, int index, Node **head, Node **tail, int *size)
{
    //checking for valid index
    if (index >= 0 && index <= *size)
    {
        Node *ptr = new Node;
        ptr->data = element;

        //optimization in insertion if index lie in first half of Doubly linked list
        if (index <= (*size) / 2)
        {
            //checking for '0' index
            if (index == 0)
            {
                //again for empty
                if ((*head) == NULL)
                {
                    ptr->next = NULL;
                    ptr->prev = NULL;
                    (*head) = (*tail) = ptr;
                }
                //and non-empty
                else
                {
                    ptr->next = (*head);
                    (*head)->prev = ptr;
                    (*head) = ptr;
                    ptr->prev = NULL;
                }
            }
            //non zero indexes
            else
            {
                Node *p;
                p = (*head);

                //loop will stop one less than index
                for (int i = 0; i < index - 1; i++)
                    p = p->next;

                ptr->next = p->next;
                ptr->prev = p;
                p->next->prev = ptr;
                p->next = ptr;
            }
        }
        //if index lie in second half of Doubly linked list
        else
        {
            //checking for last index
            if (index == *size)
            {
                ptr->prev = (*tail);
                (*tail)->next = ptr;
                (*tail) = ptr;
                ptr->next = NULL;
            }
            //indexing other than last
            else
            {
                Node *p;
                p = (*tail);

                //loop will stop one less than index
                for (int i = *size; i > index + 1; i--)
                    p = p->prev;

                ptr->prev = p->prev;
                ptr->next = p;
                p->prev->next = ptr;
                p->prev = ptr;
            }
        }

        (*size)++;
    }
    else
        cout << "Invalid Index" << endl;
}

//function for insert an element at end of Doubly Linked List
void insertAtEnd(int element, Node **head, Node **tail)
{
    Node *ptr = new Node;
    ptr->data = element;

    if ((*tail) == NULL)
    {
        ptr->next = NULL;
        ptr->prev = NULL;
        (*head) = (*tail) = ptr;
    }
    else
    {
        ptr->prev = (*tail);
        (*tail)->next = ptr;
        (*tail) = ptr;
        ptr->next = NULL;
    }
}

int main()
{
    system("cls");
    Node *head;
    Node *tail;

    head = tail = NULL;
    int size;

    size = TraverseForward(head);
    //size = TraverseBackward(tail);

    insertAtIndex(10, 0, &head, &tail, &size);
    insertAtIndex(20, 1, &head, &tail, &size);
    insertAtIndex(30, 2, &head, &tail, &size);
    insertAtIndex(40, 3, &head, &tail, &size);
    insertAtIndex(50, 4, &head, &tail, &size);
    insertAtIndex(60, 3, &head, &tail, &size);

    size = TraverseForward(head);
    //size = TraverseBackward(tail);
}