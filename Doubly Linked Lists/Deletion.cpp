#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

//function for Traverse Doubly Linked List forward
int TraverseForward(node *head)
{
    int size = 0;
    cout << endl
         << "Doubly LL->";

    while (head != NULL)
    {
        size++;
        cout << head->data << " ";
        head = head->next;
    }

    return size;
}

//function for Traverse Doubly Linked List borward
int TraverseBackward(node *tail)
{
    int size = 0;
    cout << endl
         << "Doubly LL->";

    while (tail != NULL)
    {
        size++;
        cout << tail->data << " ";
        tail = tail->prev;
    }

    return size;
}

//function for removing element from Start of Doubly Linked List
int deletefromStart(node **head, node **tail, int *size)
{
    //removing element
    int element;

    //condition for NULL doubly linked list
    if ((*head) == NULL)
        cout << "Empty Doubly Linked List" << endl;
    else
    {
        node *ptr;
        ptr = (*head);

        element = ptr->data;
        (*head) = (*head)->next;

        //condition when only one element is left in doubly linked list
        if (*head != NULL)
            (*head)->prev = NULL;
        else
            (*tail) = NULL;

        delete ptr;
        (*size)--;
    }

    return element;
}

//function for removing element from Start of Doubly Linked List
int deleteFromIndex(int index, node **head, node **tail, int *size)
{
    //removing element
    int element;

    //checking for valid indexes
    if (index >= 0 && index < *size)
    {
        node *ptr;
        //Optimization in deletion if index lie in first half of doubly linked list
        if (index <= (*size) / 2)
        {
            //checking for '0' index
            if (index == 0)
            {
                ptr = (*head);
                element = ptr->data;
                (*head) = (*head)->next;

                if ((*head) != NULL)
                    (*head)->prev = NULL;
                else
                    (*tail) = NULL;
            }
            //checking for non-zero indexes
            else
            {
                node *p;
                p = (*head);

                for (int i = 0; i < index - 1; i++)
                    p = p->next;

                ptr = p->next;
                element = ptr->data;

                p->next = ptr->next;
                ptr->next->prev = p;
            }
        }
        //Optimization in deletion if index lie in second half of doubly linked list
        else
        {
            //condition for last index
            if (index == *size - 1)
            {
                ptr = (*tail);

                element = ptr->data;
                (*tail) = (*tail)->prev;

                if (*tail != NULL)
                    (*tail)->next = NULL;
                else
                    (*head) = NULL;
            }
            //condition for indexes ohther than last
            else
            {
                node *p;
                p = (*tail);

                for (int i = *size; i > index + 1; i--)
                    p = p->prev;

                ptr = p->prev;
                element = ptr->data;

                p->prev = ptr->prev;
                ptr->prev->next = p;
            }
        }

        delete ptr;
        (*size)--;
    }
    else
        cout << "Invalid Index" << endl;

    return element;
}

//function for removing element from Start of Doubly Linked List
int deleteFromEnd(node **head, node **tail, int *size)
{
    //removing element
    int element;

    //checking for NULL doubly linked list
    if ((*tail) == NULL)
        cout << "Empty Doubly Linked List" << endl;

    else
    {
        node *ptr;
        ptr = (*tail);

        element = ptr->data;
        (*tail) = (*tail)->prev;

        //condition when only one element is left in doubly linked list
        if (*tail != NULL)
            (*tail)->next = NULL;
        else
            (*head) = NULL;

        delete ptr;
        (*size)--;
    }
    return element;
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

    size = TraverseForward(head);

    cout << endl
         << deleteFromIndex(0, &head, &tail, &size);
    cout << endl
         << deleteFromIndex(1, &head, &tail, &size);

    size = TraverseForward(head);
}