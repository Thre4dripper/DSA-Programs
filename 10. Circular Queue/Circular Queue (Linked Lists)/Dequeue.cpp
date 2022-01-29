#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

//function to display whole queue
int display(Node *front)
{
    int size = 0;
    cout << endl
         << "Circular Queue->";

    Node *ptr = new Node;
    ptr = front;

    //condition for empty circular queue
    if (ptr->next != ptr)
    {
        ptr = front->next;
        //loop must run at least one time
        do
        {
            size++;
            cout << ptr->data << " ";
            ptr = ptr->next;

        } while (ptr != front->next);
        //cause termination condition is same for both empty and to reach last element
    }
    else
        cout << "Empty" << endl;

    return size;
}

//function for removing an element from queue
int Dequeue(Node **front, Node **rear, int *size)
{
    int element;
    Node *ptr = new Node;

    //condition for empty queue
    if ((*front)->next != *front)
    {
        ptr = (*front)->next;
        element = ptr->data;

        //when queue has some elements greated than 1
        if (*size != 1)
            (*front)->next = ptr->next;

        //when queue has only last element left
        else
            (*front)->next = *front;

        //size must be decremented for above conditions
        (*size)--;
    }
    else
        cout << "Empty Circular Linked List" << endl;

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

    size = display(front);

    cout << endl
         << Dequeue(&front, &rear, &size);
    cout << endl
         << Dequeue(&front, &rear, &size);
    cout << endl
         << Dequeue(&front, &rear, &size);
    cout << endl
         << Dequeue(&front, &rear, &size);

    size = display(front);
}