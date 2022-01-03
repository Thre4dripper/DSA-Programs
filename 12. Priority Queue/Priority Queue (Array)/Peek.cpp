#include <iostream>
using namespace std;

struct node
{
    string name;
    int priority;
};

node peekStart(node arr[], int *mSize)
{

    if (*mSize == 0)
        return {"null",-1};
    return arr[0];
}

node peekEnd(node arr[], int *mSize)
{

    if (*mSize == 0)
       return {"null",-1};

    return arr[*mSize - 1];
}

node peekIndex(int index, node arr[], int *mSize)
{

    if (index < *mSize)
        return arr[*mSize - index - 1];
    else
        return {"null",-1};
}

int main()
{
    system("cls");

    node arr[] = {{"p1", 1}, {"p5", 2}, {"p4", 3}, {"p2", 4}, {"p3", 5}, {"p0", 6}};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << endl
         << peekIndex(4, arr, &size).name;

    cout << endl
         << peekStart(arr, &size).name;

    cout << endl
         << peekEnd(arr, &size).name;
}