#include <iostream>
using namespace std;

struct Node
{
    string name;
    int priority;
};

//function to remove elements from priority queue
Node dequeue(Node arr[], int *last)
{
    //assuming higher number is higher priority
    Node element;
    if (*last != 0)
    {
        element = arr[*last - 1];
        (*last)--;
    }
    else
        cout << "Queue Underflow" << endl;
    return element;
}

int main()
{
    system("cls");

    Node arr[] = {{"p1", 1}, {"p5", 2}, {"p4", 3}, {"p2", 4}, {"p3", 5}, {"p0", 6}};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << endl
         << dequeue(arr, &size).name;
    cout << endl
         << dequeue(arr, &size).name;
    cout << endl
         << dequeue(arr, &size).name;
}