#include <iostream>
using namespace std;

//queue class implementation using array
class Queue
{
private:
    int front, rear;
    int size;
    int *arr;

public:
    //constructor for initialising size , front and rear
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        arr = (int *)malloc(size * sizeof(int));
    }

    //method for push element in the queue
    void enqueue(int element)
    {
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            arr[rear] = element;
        }
        else if (rear < size - 1)
        {
            rear++;
            arr[rear] = element;
        }
        else
            cout << "\nQueue Overflow!!!\n";
    }

    //method for removing element from the queue
    int dequeue()
    {
        if (front > rear || front == -1)
        {
            cout << "\nQueue Underflow!!!\n";
            return -1;
        }
        else
        {
            int element = arr[front];
            front++;

            if (front > rear)
                front = rear = -1;
            return element;
        }
    }

    //method for getting front element from the queue
    int Front()
    {
        if (front == -1)
            return -1;
        else
            return arr[front];
    }

    //method for getting rear element from the queue
    int Rear()
    {
        if (rear == -1)
            return -1;
        else
            return arr[rear];
    }

    //method for checking if queue is empty or not
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    //method fot checking if queue is full or not
    bool isFull()
    {
        if (rear == size - 1)
            return true;
        else
            return false;
    }

    //method to display whole queue
    void display()
    {
        if (rear == -1 && front == -1)
            cout << "[ ]";
        else
        {
            cout << "\n[ ";

            for (int i = front; i <= rear; i++)
            {
                cout << arr[i];
                if (i != rear)
                    cout << " | ";
            }

            cout << " ]";
        }
    }

    //method for getting size of queue
    int Size()
    {
        if (rear == -1 && front == -1)
            return 0;
        return rear - front + 1;
    }
};

int main()
{
    system("cls");

    //queue class object declaration
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << q.Size() << endl;
    q.display();
}