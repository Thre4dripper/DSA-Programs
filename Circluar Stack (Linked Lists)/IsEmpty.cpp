#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

//function for checking circular stack is empty or not
int IsEmpty(node *top)
{
    if (top == top->next)
        return 1;
    else
        return 0;
}

int main()
{
    system("cls");

    node *top = new node;
    top->next = top;

    cout << IsEmpty(top);
}