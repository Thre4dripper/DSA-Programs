#include <iostream>
using namespace std;

//generic queue class implementation using linked list
template<typename T>
class Queue
{
private:
    //node structure for every element in queue
    struct node
    {
        T data;
        node *next;
    };

    //varibales for controlling queue flow
    node *front = NULL;
    node *rear = NULL;
    int size = 0;

public:
    //method for inserting element in the queue
    void enqueue(T element)
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
    T dequeue()
    {
        if (front != NULL)
        {
            node *ptr = front;

            T element = ptr->data;
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
    T Front()
    {
        if (front != NULL)
            return front->data;

        return -1;
    }

    //method for getting rear element from queue
    T Rear()
    {
        if (rear != NULL)
            return rear->data;

        return -1;
    }

    //method for displaying all the elements from the queue
    void display()
    {
        node *ptr = front;

        cout << "\n[ ";
        while (ptr != NULL)
        {
            cout << ptr->data;

            if (ptr->next != NULL)
                cout << " | ";

            ptr = ptr->next;
        }

        cout << " ]";
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

    //generic queue class objects declaration
    Queue<int> q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);

    q1.display();

    Queue<float> q2;
    q2.enqueue(10.3);
    q2.enqueue(20.4);
    q2.enqueue(30.45);
    q2.enqueue(40.4);
    q2.enqueue(50.9);

    q2.display();

    Queue<char> q3;
    q3.enqueue('a');
    q3.enqueue('b');
    q3.enqueue('c');
    q3.enqueue('d');

    q3.display();
}