#include <iostream>
using namespace std;

//priority queue class implementation using linked list
class PQueue
{
private:
    struct node
    {
        string name;
        int priority;
        node *next;
    };

    node *front = NULL;
    node *rear = NULL;
    int size = 0;

public:
    //function for inserting element in priority queue
    void enqueue(node element)
    {
        //elements are inserting acc to their priorities

        node *ptr = new node;
        ptr = &element;

        ptr->next = NULL;

        if (front == NULL)
        {
            front = rear = ptr;
        }
        else if (element.priority < front->priority)
        {
            ptr->next = front;
            front = ptr;
        }
        else
        {
            node *p = front;
            node *q = NULL;

            while (p != NULL && element.priority > p->priority)
            {
                q = p;
                p = p->next;
            }

            ptr->next = p;
            q->next = ptr;

            if (p == NULL)
                rear = ptr;
        }

        size++;
    }

    //function for deleting elements from priority queue
    string dequeue()
    {
        string element;
        if (front != NULL)
        {
            node *ptr = front;
            element = front->name;
            front = front->next;

            if (front == NULL)
                rear = NULL;
            delete ptr;

            size--;
        }
        else
        {
            cout << "Queue Underflow!!!" << endl;
            return NULL;
        }
        return element;
    }

    //method for getting front element from the queue
    string Front()
    {
        if (front == NULL)
            return NULL;
        else
            return front->name;
    }

    //method for getting rear element from the queue
    string Rear()
    {
        if (rear == NULL)
            return NULL;
        else
            return rear->name;
    }

    //method for checking if queue is empty or not
    bool isEmpty()
    {
        if (front == NULL && rear == NULL)
            return true;
        else
            return false;
    }

    //function for displaying priority queue
    void display()
    {
        struct node *p = front;

        cout << endl
             << "PQ: ";
        while (p != NULL)
        {
            cout << "[" << p->name << "|" << p->priority << "] ";
            p = p->next;
        }
    }

    //method for getting size of queue
    int Size()
    {
        return size;
    }
};
int main()
{
    system("cls");

    //priority queue class object declaration
    PQueue pq;
    pq.enqueue({"p1", 4});
    pq.enqueue({"p2", 2});
    pq.enqueue({"p3", 5});
    pq.enqueue({"p4", 3});
    pq.enqueue({"p5", 9});

    cout << pq.dequeue() << endl;
    cout << pq.dequeue() << endl;
    cout << pq.dequeue() << endl;

    cout << pq.Front() << " " << pq.Rear() << endl;
    cout << pq.Size();

    pq.display();
}