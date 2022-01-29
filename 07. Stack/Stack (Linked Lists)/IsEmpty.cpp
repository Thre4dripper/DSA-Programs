#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

///function for checking stack is empty or not
int IsEmpty(Node *top)
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    system("cls");

    Node *top;

    top = NULL;

    cout << IsEmpty(top);
}