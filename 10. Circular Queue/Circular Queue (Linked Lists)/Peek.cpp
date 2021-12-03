#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

//function to peek in queue
int Peek(int index, node *front, node *rear, int size)
{
    int element;
    node *ptr = new node;

    //index should be valid
    if (index >= 0 && index < size)
    {
        ptr = front->next;
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

    node *front = new node;
    node *rear = new node;

    node *second = new node;
    node *third = new node;
    node *forth = new node;
    node *fifth = new node;

    int size;
    front->next = front;
    rear->next = rear;

    front->next = second;

    second->data = 10;
    second->next = third;

    third->data = 20;
    third->next = forth;

    forth->data = 30;
    forth->next = fifth;

    fifth->data = 40;
    fifth->next = second;

    size = 4;
    cout << Peek(3, front, rear, size);
}