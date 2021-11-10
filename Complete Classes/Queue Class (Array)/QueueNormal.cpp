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

    //function for push element in the queue
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

    //function for removing element from the queue
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

    //function for getting front element from the queue
    int Front()
    {
        if (front == -1)
            return -1;
        else
            return arr[front];
    }

    //function for getting rear element from the queue
    int Rear()
    {
        if (rear == -1)
            return -1;
        else
            return arr[rear];
    }

    //function for checking if queue is empty or not
    int isEmpty()
    {
        if (front == -1 && rear == -1)
            return 1;
        else
            return 0;
    }

    //function fot checking if queue is full or not
    int isFull()
    {
        if (rear == size - 1)
            return 1;
        else
            return 0;
    }

    //function to display whole queue
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

    //function for getting size of queue
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