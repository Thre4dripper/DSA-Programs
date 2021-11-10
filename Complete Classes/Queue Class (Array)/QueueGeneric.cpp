#include <iostream>
using namespace std;

//generic queue class implementation using array
template <typename T>
class Queue
{
private:
    int front, rear;
    int size;
    T *arr;

public:
    //constructor for initialising size , front and rear
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        arr = (T *)malloc(size * sizeof(T));
    }

    //method for inserting element in the queue
    void enqueue(T element)
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
    T dequeue()
    {
        if (front > rear || front == -1)
        {
            cout << "\nQueue Underflow!!!\n";
            return -1;
        }
        else
        {
            T element = arr[front];
            front++;

            if (front > rear)
                front = rear = -1;
            return element;
        }
    }

    //method for getting front element from the queue
    T Front()
    {
        if (front == -1)
            return -1;
        else
            return arr[front];
    }

    //method for getting rear element from the queue
    T Rear()
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

    //generic queue class objects declaration
    Queue<int> q1(5);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);

    q1.display();

    Queue<float> q2(5);
    q2.enqueue(10.51);
    q2.enqueue(20.2);
    q2.enqueue(30.65);
    q2.enqueue(40.21);
    q2.enqueue(50.32);

    q2.display();

    Queue<char> q3(4);
    q3.enqueue('a');
    q3.enqueue('b');
    q3.enqueue('c');
    q3.enqueue('d');

    q3.display();
}