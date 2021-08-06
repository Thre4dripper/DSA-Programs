#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

int Peek(int index, node *top, int size)
{
    int element;

    if (index >= 0 && index < size)
    {

        node *ptr = new node;
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

    node *top = new node;
    node *second = new node;
    node *third = new node;
    node *forth = new node;
    node *fifth = new node;

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