#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

//Function to display whole circular stack
int display(Node *top)
{
    int size = 0;

    cout << endl
         << "Circular Stack->";

    Node *ptr = new Node;
    ptr = top;

    if (ptr->next != ptr)
    {
        ptr = top->next;

        //loop must run atleast one time
        do
        {
            size++;
            cout << ptr->data << " ";
            ptr = ptr->next;

        } while (ptr != top->next);
        //cause condition for termination is same for empty and last node
    }
    else
        cout << "Empty" << endl;

    return size;
}

//Circular Stack Pop Operation
int Pop(Node **top, int *size)
{
    int element;

    if ((*top)->next == *top)
        cout << "Empty Circular Linked List" << endl;
    else
    {
        Node *ptr = new Node;
        ptr = (*top)->next;

        element = ptr->data;
        if (*size != 1)
        {
            Node *p = new Node;
            p = (*top)->next;

            while (p->next != (*top)->next)
            {
                p = p->next;
            }

            p->next = ptr->next;
            (*top)->next = ptr->next;
        }
        else
        {
            (*top)->next = *top;
        }

        (*size)--;
        delete ptr;
    }
    return element;
}

int main()
{
    system("cls");

    Node *top = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *forth = new Node;
    Node *fifth = new Node;

    int size;
    top->next = top;

    top->next = second;

    second->data = 10;
    second->next = third;

    third->data = 20;
    third->next = forth;

    forth->data = 30;
    forth->next = fifth;

    fifth->data = 40;
    fifth->next = second;

    size = display(top);

    cout << endl
         << Pop(&top, &size);

    cout << endl
         << Pop(&top, &size);
    cout << endl
         << Pop(&top, &size);
    cout << endl
         << Pop(&top, &size);

    size = display(top);
}