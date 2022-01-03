#include <iostream>
using namespace std;

void display(int arr[], int front, int rear)
{
    cout << endl;
    for (int i = front; i <= rear; i++)
        cout << arr[i] << " ";
}

//function for inserting element at start
void enqueueStart(int element, int arr[], int *front, int *rear, int mSize)
{

    if (*rear < mSize - 1)
    {
        if (*front == -1)
            (*front) = (*rear) = 0;

        else
            (*rear)++;

        for (int i = (*rear); i > (*front); i--)
            arr[i] = arr[i - 1];

        arr[0] = element;
    }
    else
        cout << "Queue Overflow" << endl;
}

//function for inserting element at end
void enqueueEnd(int element, int arr[], int *front, int *rear, int mSize)
{

    if (*rear < mSize - 1)
    {
        if (*front == -1)
            (*front) = (*rear) = 0;

        else
            (*rear)++;

        arr[(*rear)] = element;
    }
    else
        cout << "Queue Overflow" << endl;
}

int main()
{
    system("cls");

    int mSize = 4;
    int arr[mSize];
    int front = -1;
    int rear = -1;

    enqueueEnd(10, arr, &front, &rear, mSize);
    enqueueEnd(20, arr, &front, &rear, mSize);
    enqueueStart(25, arr, &front, &rear, mSize);
    enqueueEnd(30, arr, &front, &rear, mSize);
    enqueueEnd(40, arr, &front, &rear, mSize);

    display(arr, front, rear);
}