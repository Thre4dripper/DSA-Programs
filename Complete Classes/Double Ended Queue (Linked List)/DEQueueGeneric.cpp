#include <iostream>
using namespace std;

//double ended queue class implementation using linked list
template <typename T>
class DEQueue
{
private:
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
    //function to insert element at start
    void enqueueStart(T element)
    {
        node *ptr = new node;

        ptr->data = element;
        ptr->next = NULL;
        if (front == NULL)
            front = rear = ptr;

        else
        {
            ptr->next = front;
            front = ptr;
        }

        size++;
    }

    //function to insert element at end
    void enqueueEnd(T element)
    {
        node *ptr = new node;

        ptr->data = element;
        ptr->next = NULL;
        if (front == NULL)
            front = rear = ptr;

        else
        {
            rear->next = ptr;
            rear = ptr;
        }
        size++;
    }

    //function to delete element from start
    T dequeueStart()
    {
        T element = 0;
        if (front != NULL)
        {
            node *ptr = front;
            element = front->data;
            front = front->next;

            if (front == NULL)
                rear = NULL;

            delete ptr;

            size--;
        }
        else
            cout << "Queue Underflow" << endl;
        return element;
    }

    //function to delete element from end
    T dequeueEnd()
    {
        T element = 0;

        if (front != NULL)
        {
            //only one node is left, below logic doesn't work on this
            //otherwise u have to use two sliding pointers
            if (front->next == NULL)
                return dequeueStart();

            node *ptr = front;

            //reching second last node
            while (ptr->next->next != NULL)
                ptr = ptr->next;

            element = ptr->next->data;

            delete ptr->next;
            ptr->next = NULL;
            rear = ptr;

            size--;
        }
        else
            cout << "Queue Underflow" << endl;
        return element;
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

        cout << "[ ";
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
    DEQueue<int> q1;
    q1.enqueueStart(10);
    q1.enqueueStart(20);
    q1.enqueueEnd(30);
    q1.enqueueEnd(40);
    q1.enqueueStart(50);

    cout << endl;
    q1.display();

    DEQueue<float> q2;
    q2.enqueueStart(3.6);
    q2.enqueueStart(4.2);
    q2.enqueueEnd(9.8);
    q2.enqueueEnd(5.6);
    q2.enqueueStart(4.1);

    cout << endl;
    q2.display();

    DEQueue<char> q3;
    q3.enqueueStart('a');
    q3.enqueueStart('b');
    q3.enqueueEnd('c');
    q3.enqueueEnd('d');
    q3.enqueueStart('e');

    cout << endl;
    q3.display();
}