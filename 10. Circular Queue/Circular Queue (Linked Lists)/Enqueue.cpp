#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

//function to display whole queue
int display(node *front)
{
    int size = 0;
    cout << endl
         << "Circular Queue->";

    node *ptr = new node;
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

//function to insert an element in circular queue
void Enqueue(int element, node **front, node **rear)
{
    node *ptr = new node;
    ptr->data = element;

    //when queue is empty, it will create one
    if ((*front)->next == (*front))
    {
        (*front)->next = (*rear)->next = ptr;
        ptr->next = ptr;
    }
    //condition for already created queue
    else
    {
        ptr->next = (*front)->next;
        (*rear)->next->next = ptr;
        (*rear)->next = ptr;
    }
}


int main()
{
    system("cls");

    node *front = new node;
    front->next = front;

    node *rear = new node;
    rear->next = rear;

    int size;

    size = display(front);

    Enqueue(10, &front, &rear);
    Enqueue(20, &front, &rear);
    Enqueue(30, &front, &rear);

    size = display(front);
}