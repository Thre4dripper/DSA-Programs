#include <iostream>
using namespace std;

struct Node
{
    string name;
    int priority;
    Node *next;
};

//for traverse, count and display all nodes of linked list
int display(Node *front)
{
    int size = 0;
    cout << endl;
    if (front == NULL)
    {
        printf("\nQueue is empty");
        return 0;
    }
    while (front != NULL)
    {
        cout << "[" << front->name << "|" << front->priority << "] ";
        front = front->next;
        size++;
    }
    return size;
}

Node peekStart(Node **head, Node **rear)
{
    return *(*head);
}

Node peekEnd(Node **head, Node **rear)
{
    return *(*rear);
}

Node peekIndex(int index, Node **head, Node **rear, int size)
{
    Node element = {"null", -1};

    if (index < size && index >= 0)
    {
        Node *ptr = new Node;
        ptr = *head;
        for (int i = 0; i < index && ptr->next != NULL; i++)
        {
            ptr = ptr->next;
        }
        element = *ptr;
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

    first->name = "p2";
    first->priority = 5;
    first->next = second;

    second->name = "p1";
    second->priority = 4;
    second->next = third;

    third->name = "p5";
    third->priority = 3;
    third->next = forth;

    forth->name = "p3";
    forth->priority = 2;
    forth->next = fifth;

    fifth->name = "p4";
    fifth->priority = 1;
    fifth->next = NULL;

    size = display(first);

    cout << endl
         << peekIndex(2, &front, &rear, size).name;
    cout << endl
         << peekStart(&front, &rear).name;
    cout << endl
         << peekEnd(&front, &rear).name;
}