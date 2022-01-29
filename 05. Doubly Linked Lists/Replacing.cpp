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
int TraverseBackward(Node *tail)
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

//function for replacing element from Start of Doubly Linked List
int replaceFromStart(int element, Node **head, Node **tail)
{
    //removing element
    int initelement;

    //condition for NULL doubly linked list
    if ((*head) == NULL)
        cout << "Empty Doubly Linked List" << endl;
    else
    {
        Node *ptr;
        ptr = (*head);

        initelement = ptr->data;
        ptr->data = element;
    }

    return initelement;
}

//function for replacing element from any Index of Doubly Linked List
int replaceFromIndex(int element, int index, Node **head, Node **tail, int *size)
{
    //removing element
    int initelement;

    //checking for valid indexes
    if (index >= 0 && index < *size)
    {
        Node *ptr;
        //Optimization in deletion if index lie in first half of doubly linked list
        if (index <= (*size) / 2)
        {
            //checking for '0' index
            if (index == 0)
            {
                ptr = (*head);
                initelement = ptr->data;
                ptr->data = element;
            }
            //checking for non-zero indexes
            else
            {
                Node *p;
                p = (*head);

                for (int i = 0; i < index - 1; i++)
                    p = p->next;

                ptr = p->next;
                initelement = ptr->data;
                ptr->data = element;
            }
        }
        //Optimization in deletion if index lie in second half of doubly linked list
        else
        {
            //condition for last index
            if (index == *size - 1)
            {
                ptr = (*tail);

                initelement = ptr->data;
                ptr->data = element;
            }
            //condition for indexes ohther than last
            else
            {
                Node *p;
                p = (*tail);

                for (int i = *size - 1; i > index + 1; i--)
                    p = p->prev;

                ptr = p->prev;
                initelement = ptr->data;
                ptr->data = element;
            }
        }
    }
    else
        cout << "Invalid Index" << endl;

    return initelement;
}

//function for replacing element from End of Doubly Linked List
int replaceFromEnd(int element, Node **head, Node **tail)
{
    //removing element
    int initelement;

    //checking for NULL doubly linked list
    if ((*tail) == NULL)
        cout << "Empty Doubly Linked List" << endl;

    else
    {
        Node *ptr;
        ptr = (*tail);

        initelement = ptr->data;
        ptr->data = element;
    }
    return initelement;
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

    size = TraverseForward(head);

    cout << endl
         << replaceFromIndex(60, 1, &head, &tail, &size);
    cout << endl
         << replaceFromIndex(70, 3, &head, &tail, &size);
    cout << endl
         << replaceFromIndex(80, 4, &head, &tail, &size);

    size = TraverseForward(head);
}