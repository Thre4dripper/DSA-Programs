#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int Peek(int index, Node *top, int size)
{
    int element;

    if (index >= 0 && index < size)
    {

        Node *ptr = new Node;
        ptr = top->next;

        for (int i = 0; i < index; i++)
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

    Node *top = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *forth = new Node;
    Node *fifth = new Node;

    int size;
    top->next = top;

    top->next = second;

    second->data = 10;
    second->next = third;

    third->data = 20;
    third->next = forth;

    forth->data = 30;
    forth->next = fifth;

    fifth->data = 40;
    fifth->next = second;

    size = 4;

    cout << endl
         << Peek(2, top, size);
}