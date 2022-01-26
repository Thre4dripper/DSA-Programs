#include <iostream>
using namespace std;

//generic double ended queue class implementation using array
template <typename T>
class DEQueue
{
private:
    int front, rear;
    int size;
    T *arr;

public:
    //constructor for initialising size , front and rear
    DEQueue(int size)
    {
        front = rear = -1;
        this->size = size;
        arr = (T *)malloc(size * sizeof(T));
    }

    //function for inserting element at start
    void enqueueStart(T element)
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
    void enqueueEnd(T element)
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
    T dequeueStart()
    {

        T element;
        if (rear >= 0)
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
    T dequeueEnd()
    {
        T element;
        if (rear >= 0)
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

    //generic double ended queue class objects declaration
    DEQueue<int> q1(5);
    q1.enqueueStart(10);
    q1.enqueueStart(20);
    q1.enqueueEnd(30);
    q1.enqueueEnd(40);
    q1.enqueueStart(50);

    cout << q1.Front() << " " << q1.Rear();
    q1.display();

    DEQueue<float> q2(5);
    q2.enqueueStart(2.2);
    q2.enqueueStart(3.2);
    q2.enqueueEnd(1.3);
    q2.enqueueEnd(5.8);
    q2.enqueueStart(7.6);

    cout << endl
         << endl
         << q2.Front() << " " << q2.Rear();
    q2.display();

    DEQueue<char> q3(5);
    q3.enqueueStart('a');
    q3.enqueueStart('b');
    q3.enqueueEnd('c');
    q3.enqueueEnd('d');
    q3.enqueueStart('e');

    cout << endl
         << endl
         << q3.Front() << " " << q3.Rear();
    q3.display();
}