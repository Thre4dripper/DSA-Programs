#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

//Function to display whole circular stack
int display(node *top)
{
    int size = 0;

    cout << endl
         << "Circular Stack->";

    node *ptr = new node;
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
int Pop(node **top, int *size)
{
    int element;

    if ((*top)->next == *top)
        cout << "Empty Circular Linked List" << endl;
    else
    {
        node *ptr = new node;
        ptr = (*top)->next;

        element = ptr->data;
        if (*size != 1)
        {
            node *p = new node;
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

    node *top = new node;
    node *second = new node;
    node *third = new node;
    node *forth = new node;
    node *fifth = new node;

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