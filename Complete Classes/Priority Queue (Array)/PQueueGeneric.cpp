#include <iostream>
using namespace std;

//generic priority queue class implementation using array
template <typename T>
class PQueue
{
private:
    struct Node
    {
        T name;
        int priority;
    };

    int front, rear;
    int size;
    Node *arr;

public:
    //constructor for initialising size , front and rear
    PQueue(int size)
    {
        front = rear = -1;
        this->size = size;
        arr = (Node *)malloc(size * sizeof(Node));
    }

    //function to insert elements in priority queue
    void enqueue(Node element)
    {
        //Element always entered in queue acc to priorities

        if (rear < size - 1)
        {
            if (front == -1)
            {
                front = rear = 0;
                arr[front] = element;
            }
            else if (element.priority < arr[0].priority)
            {
                rear++;
                arr[rear] = arr[0];
                arr[0] = element;
            }
            else
            {
                int index = 0;

                while (index <= rear && element.priority >= arr[index].priority)
                    index++;

                rear++;
                for (int i = rear; i > index; i--)
                {
                    arr[i] = arr[i - 1];
                }
                arr[index] = element;
            }
        }
        else
            cout << "Queue Overflow!!!" << endl;
    }

    //function to remove elements from priority queue
    Node dequeue()
    {
        //assuming higher number is higher priority
        Node element;
        if (rear >= 0)
        {
            element = arr[0];
            for (int i = 0; i < rear; i++)
                arr[i] = arr[i + 1];

            if (rear == 0)
                front = rear = -1;
            else
                rear--;
        }
        else
            cout << "Queue Underflow" << endl;
        return element;
    }

    //method for getting front element from the queue
    Node Front()
    {
        Node element;
        if (front == -1)
            return element;
        else
            return arr[front];
    }

    //method for getting rear element from the queue
    Node Rear()
    {
        Node element;
        if (rear == -1)
            return element;
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
        cout << endl
             << "PQ: ";
        for (int i = 0; i <= rear; i++)
            cout << "[" << arr[i].name << "|" << arr[i].priority << "] ";
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

    //genric double ended queue class objects declaration
    PQueue<string> pq1(5);
    pq1.enqueue({"p1", 5});
    pq1.enqueue({"p2", 1});
    pq1.enqueue({"p3", 2});
    pq1.enqueue({"p4", 2});
    pq1.enqueue({"p6", 3});

    cout << pq1.Front().name << " " << pq1.Rear().name << endl;
    pq1.display();

    PQueue<char> pq2(5);
    pq2.enqueue({'a', 5});
    pq2.enqueue({'b', 1});
    pq2.enqueue({'c', 2});
    pq2.enqueue({'d', 2});
    pq2.enqueue({'e', 3});

    cout << pq2.Front().name << " " << pq2.Rear().name << endl;
    pq2.display();
}
