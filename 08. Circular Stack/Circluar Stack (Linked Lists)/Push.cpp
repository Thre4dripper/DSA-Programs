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

//Circular Stack Push Operation
void Push(int element, Node **top)
{
    Node *ptr = new Node;
    ptr->data = element;

    if ((*top)->next == *top)
    {
        (*top)->next = ptr;
        ptr->next = ptr;
    }
    else
    {
        Node *p = new Node;
        p = (*top)->next;

        while (p->next != (*top)->next)
        {
            p = p->next;
        }

        ptr->next = (*top)->next;
        (*top)->next = ptr;
        p->next = ptr;
    }
}

int main()
{
    system("cls");

    Node *top = new Node;
    int size;

    top->next = top;

    size = display(top);

    Push(10, &top);
    Push(20, &top);
    Push(30, &top);
    Push(40, &top);

    size = display(top);
}