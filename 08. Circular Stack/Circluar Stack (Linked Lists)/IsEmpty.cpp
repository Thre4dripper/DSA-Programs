#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

//function for checking circular stack is empty or not
int IsEmpty(Node *top)
{
    if (top == top->next)
        return 1;
    else
        return 0;
}

int main()
{
    system("cls");

    Node *top = new Node;
    top->next = top;

    cout << IsEmpty(top);
}