#include <iostream>
using namespace std;

//priority queue class implementation using linked list
class PQueue
{
private:
    struct Node
    {
        string name;
        int priority;
        Node *next;
    };

    Node *front = NULL;
    Node *rear = NULL;
    int size = 0;

public:
    //function for inserting element in priority queue
    void enqueue(Node element)
    {
        //elements are inserting acc to their priorities

        Node *ptr = new Node;
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
            Node *p = front;
            Node *q = NULL;

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
    Node dequeue()
    {
        Node element = {"null", -1};
        if (front != NULL)
        {
            Node *ptr = front;
            element = *front;
            front = front->next;

            if (front == NULL)
                rear = NULL;
            delete ptr;

            size--;
        }
        else
            cout << "Queue Underflow!!!" << endl;

        return element;
    }

    //method for getting front element from the queue
    Node Front()
    {
        Node element = {"null", -1};
        if (front == NULL)
            return element;
        else
            return *front;
    }

    //method for getting rear element from the queue
    Node Rear()
    {
        Node element = {"null", -1};
        if (rear == NULL)
            return element;
        else
            return *rear;
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
        struct Node *p = front;

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

    cout << pq.dequeue().name << endl;
    cout << pq.dequeue().name << endl;
    cout << pq.dequeue().name << endl;

    cout << pq.Front().name << " " << pq.Rear().name << endl;
    cout << pq.Size();

    pq.display();
}