#include <iostream>
using namespace std;

struct Node
{
    string name;
    int priority;
    Node *next;
};

//function for displaying priority queue
void display(Node *front)
{
    struct Node *p = front;
    if (p == NULL)
    {
        printf("\nQueue is empty");
        return;
    }
    printf("\nQueue is : ");
    while (p != NULL)
    {
        cout << "[" << p->name << "|" << p->priority << "] ";
        p = p->next;
    }
}

//function for inserting element in priority queue
void enqueue(Node element, Node **front, Node **rear)
{
    //elements are inserting acc to their priorities

    Node *ptr = new Node;
    ptr = &element;
    
    ptr->next = NULL;

    if ((*front) == NULL)
    {
        (*front) = (*rear) = ptr;
    }
    else if (element.priority < (*front)->priority)
    {
        ptr->next = (*front);
        (*front) = ptr;
    }
    else
    {
        Node *p = (*front);
        Node *q = NULL;

        while (p != NULL && element.priority > p->priority)
        {
            q = p;
            p = p->next;
        }

        ptr->next = p;
        q->next = ptr;

        if (p == NULL)
            (*rear) = ptr;
    }
}

int main()
{
    system("cls");
    Node *front = NULL;
    Node *rear = NULL;

    display(front);

    enqueue({"p1", 1}, &front, &rear);
    enqueue({"p2", 5}, &front, &rear);
    enqueue({"p3", 4}, &front, &rear);
    enqueue({"p4", 2}, &front, &rear);

    display(front);
}