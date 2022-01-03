#include <iostream>
using namespace std;

struct node
{
    string name;
    int priority;
    node *next;
};

//function for displaying priority queue
void display(node *front)
{
    struct node *p = front;
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
void enqueue(node element, node **front, node **rear)
{
    //elements are inserting acc to their priorities

    node *ptr = new node;
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
        node *p = (*front);
        node *q = NULL;

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
    node *front = NULL;
    node *rear = NULL;

    display(front);

    enqueue({"p1", 1}, &front, &rear);
    enqueue({"p2", 5}, &front, &rear);
    enqueue({"p3", 4}, &front, &rear);
    enqueue({"p4", 2}, &front, &rear);

    display(front);
}