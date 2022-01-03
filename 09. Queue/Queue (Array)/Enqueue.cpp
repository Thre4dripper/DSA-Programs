#include <iostream>
using namespace std;

void display(int arr[], int front, int rear)
{
    cout << endl;
    for (int i = 0; i <= rear; i++)
        cout << arr[i] << " ";
}

void enqueue(int element, int arr[], int *front, int *rear, int mSize)
{
    //Element always entered in queue from front

    if (*rear < mSize-1)
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

int main()
{
    system("cls");

    int mSize = 4;
    int arr[mSize];
    int front = -1;
    int rear = -1;

    display(arr, front, rear);

    enqueue(50, arr, &front, &rear, mSize);
    enqueue(20, arr, &front, &rear, mSize);
    enqueue(30, arr, &front, &rear, mSize);
    enqueue(45, arr, &front, &rear, mSize);
    enqueue(21, arr, &front, &rear, mSize);

    display(arr, front, rear);
}