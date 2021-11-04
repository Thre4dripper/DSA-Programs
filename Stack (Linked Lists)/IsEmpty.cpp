#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

///function for checking stack is empty or not
int IsEmpty(node *top)
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    system("cls");

    node *top;

    top = NULL;

    cout << IsEmpty(top);
}