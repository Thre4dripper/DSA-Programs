#include <iostream>
using namespace std;

struct node
{
    string name;
    int priority;
};

void display(node arr[], int front, int rear)
{
    if (front = -1)
    {
        cout << "\nQueue is Empty";
        return;
    }
    cout << endl
         << "PQ: ";
    for (int i = 0; i <= rear; i++)
        cout << "[" << arr[i].name << "|" << arr[i].priority << "] ";
}

//function to insert elements in priority queue
void enqueue(node element, node arr[], int *front, int *rear, int mSize)
{
    //Element always entered in queue acc to priorities

    if (*rear < mSize - 1)
    {
        if (*front == -1)
        {
            (*front) = (*rear) = 0;
            arr[(*front)] = element;
        }
        else if (element.priority < arr[0].priority)
        {
            (*rear)++;
            arr[(*rear)] = arr[0];
            arr[0] = element;
        }
        else
        {
            int index = 0;

            while (index <= (*rear) && element.priority >= arr[index].priority)
                index++;

            (*rear)++;
            for (int i = *rear; i > index; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[index] = element;
        }
    }
    else
        cout << "Queue Overflow" << endl;
}

int main()
{
    system("cls");

    int mSize = 5;
    node arr[mSize];
    int front = -1;
    int rear = -1;

    display(arr, front, rear);

    enqueue({"p1", 1}, arr, &front, &rear, mSize);
    enqueue({"p2", 5}, arr, &front, &rear, mSize);
    enqueue({"p3", 2}, arr, &front, &rear, mSize);
    enqueue({"p4", 1}, arr, &front, &rear, mSize);
    enqueue({"p5", 3}, arr, &front, &rear, mSize);

    display(arr, front, rear);
}