#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

//for traverse and display all nodes of linked list
int display(Node *head)
{
    int size = 0;
    cout << endl;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
        size++;
    }
    return size;
}

//function to peek at start
int peekStart(Node **head, Node **rear)
{
    return (*head)->data;
}

//function to peek at end
int peekEnd(Node **head, Node **rear)
{
    return (*rear)->data;
}

//function to peek at index
int peekIndex(int index, Node **head, Node **rear, int size)
{
    int element = NULL;

    if (index < size && index >= 0)
    {
        Node *ptr = new Node;
        ptr = *head;
        for (int i = 0; i < index && ptr->next != NULL; i++)
        {
            ptr = ptr->next;
        }
        element = ptr->data;
    }
    else
        cout << "Invalid Index" << endl;
    return element;
}

int main()
{
    system("cls");

    int size;
    Node *first = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *forth = new Node;
    Node *fifth = new Node;

    Node *front = first;
    Node *rear = fifth;

    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = forth;

    forth->data = 40;
    forth->next = fifth;

    fifth->data = 50;
    fifth->next = NULL;

    size = display(first);

    cout << endl
         << peekIndex(2, &front, &rear, size);
    cout << endl
         << peekStart(&front, &rear);
    cout << endl
         << peekEnd(&front, &rear);
}