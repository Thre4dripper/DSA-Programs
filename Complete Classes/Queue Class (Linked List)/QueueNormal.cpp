#include <iostream>
using namespace std;

//queue class implementation using linked list
class Queue
{
private:
    //node structure for every element in queue
    struct node
    {
        int data;
        node *next;
    };

    //varibales for controlling queue flow
    node *front = NULL;
    node *rear = NULL;
    int size = 0;

public:
    //method for inserting element in the queue
    void enqueue(int element)
    {
        node *ptr = new node;
        ptr->data = element;
        ptr->next = NULL;

        if (front == NULL)
        {
            front = rear = ptr;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
        }

        size++;
    }

    //method for removing element from the queue
    int dequeue()
    {
        if (front != NULL)
        {
            node *ptr = front;

            int element = ptr->data;
            front = front->next;

            size--;
            delete ptr;

            return element;
        }
        else
            cout << "\nQueue Underflow!!!\n";

        return -1;
    }

    //method for getting front element from queue
    int Front()
    {
        if (front != NULL)
            return front->data;

        return -1;
    }

    //method for getting rear element from queue
    int Rear()
    {
        if (rear != NULL)
            return rear->data;

        return -1;
    }

    //method for displaying all the elements from the queue
    void display()
    {
        node *ptr = front;

        cout << "[ ";
        while (ptr != NULL)
        {
            cout << ptr->data;

            if (ptr->next != NULL)
                cout << " | ";

            ptr = ptr->next;
        }

        cout << "]";
    }

    //method for checking if queue is empty or not
    bool isEmpty()
    {
        if (front == NULL && rear == NULL)
            return true;

        else
            return false;
    }

    //there is no isFull operation in Linked list implementation because of dynamic allocation
    int Size()
    {
        return size;
    }
};

int main()
{
    system("cls");

    //queue class object declaration
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << q.dequeue() << endl;
    q.display();
}