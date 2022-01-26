#include <iostream>
using namespace std;

//double ended queue class implementation using array
class DEQueue
{
private:
    int front, rear;
    int size;
    int *arr;

public:
    //constructor for initialising size , front and rear
    DEQueue(int size)
    {
        front = rear = -1;
        this->size = size;
        arr = (int *)malloc(size * sizeof(int));
    }

    //function for inserting element at start
    void enqueueStart(int element)
    {

        if (rear < size - 1)
        {
            if (front == -1)
                front = rear = 0;

            else
                rear++;

            for (int i = rear; i > front; i--)
                arr[i] = arr[i - 1];

            arr[0] = element;
        }
        else
            cout << "Queue Overflow" << endl;
    }

    //function for inserting element at end
    void enqueueEnd(int element)
    {

        if (rear < size - 1)
        {
            if (front == -1)
                front = rear = 0;

            else
                rear++;

            arr[rear] = element;
        }
        else
            cout << "Queue Overflow" << endl;
    }

    //function for deleting element from start
    int dequeueStart()
    {

        int element;
        if (size != 0)
        {
            element = arr[0];
            for (int i = 0; i < rear; i++)
                arr[i] = arr[i + 1];

            if (rear == 0)
                rear = front = -1;
            else
                rear--;
        }
        else
            cout << "Queue Underflow" << endl;
        return element;
    }

    //function for deleting element from end
    int dequeueEnd()
    {
        int element;
        if (size != 0)
        {
            element = arr[rear];

            if (rear == 0)
                rear = front = -1;
            else
                rear--;
        }
        else
            cout << "Queue Underflow" << endl;
        return element;
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
            cout << "\n[ ]";
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

    //double ended queue class object declaration
    DEQueue q(5);
    q.enqueueStart(10);
    q.enqueueStart(20);
    q.enqueueEnd(30);
    q.enqueueEnd(40);
    q.enqueueStart(50);

    cout << endl
         << q.Size();
    cout << endl
         << q.isFull();
    cout << endl
         << q.Front() << " " << q.Rear();
    q.display();
}