#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int display(Node *front)
{
    int size = 0;
    cout << endl;
    while (front != NULL)
    {
        cout << front->data << " ";
        front = front->next;
        size++;
    }

    return size;
}
void enqueue(int element, Node **front, Node **rear)
{
    Node *ptr = new Node;

    ptr->data = element;
    ptr->next = NULL;
    if (*front == NULL)
        *front = *rear = ptr;

    else
    {
        (*rear)->next = ptr;
        *rear = ptr;
    }
}

int main()
{
    system("cls");
    Node *front = NULL;
    Node *rear = NULL;

    display(front);
    enqueue(10, &front, &rear);
    enqueue(20, &front, &rear);
    enqueue(30, &front, &rear);

    display(front);
}