#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

//for traverse and display all nodes of linked list
int display(node *head)
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
int peekStart(node **head, node **rear)
{
    return (*head)->data;
}

//function to peek at end
int peekEnd(node **head, node **rear)
{
    return (*rear)->data;
}

//function to peek at index
int peekIndex(int index, node **head, node **rear, int size)
{
    int element = NULL;

    if (index < size && index >= 0)
    {
        node *ptr = new node;
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
    node *first = new node;
    node *second = new node;
    node *third = new node;
    node *forth = new node;
    node *fifth = new node;

    node *front = first;
    node *rear = fifth;

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