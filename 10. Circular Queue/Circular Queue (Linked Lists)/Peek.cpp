#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

//function to peek in queue
int Peek(int index, Node *front, Node *rear, int size)
{
    int element;
    Node *ptr = new Node;

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

    Node *front = new Node;
    Node *rear = new Node;

    Node *second = new Node;
    Node *third = new Node;
    Node *forth = new Node;
    Node *fifth = new Node;

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