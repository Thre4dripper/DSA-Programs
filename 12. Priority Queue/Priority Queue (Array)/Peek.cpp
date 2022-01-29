#include <iostream>
using namespace std;

struct Node
{
    string name;
    int priority;
};

Node peekStart(Node arr[], int *mSize)
{

    if (*mSize == 0)
        return {"null",-1};
    return arr[0];
}

Node peekEnd(Node arr[], int *mSize)
{

    if (*mSize == 0)
       return {"null",-1};

    return arr[*mSize - 1];
}

Node peekIndex(int index, Node arr[], int *mSize)
{

    if (index < *mSize)
        return arr[*mSize - index - 1];
    else
        return {"null",-1};
}

int main()
{
    system("cls");

    Node arr[] = {{"p1", 1}, {"p5", 2}, {"p4", 3}, {"p2", 4}, {"p3", 5}, {"p0", 6}};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << endl
         << peekIndex(4, arr, &size).name;

    cout << endl
         << peekStart(arr, &size).name;

    cout << endl
         << peekEnd(arr, &size).name;
}