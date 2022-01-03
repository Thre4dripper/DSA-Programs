#include <iostream>
using namespace std;

int dequeue(int arr[], int *last)
{
    int element;
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

    int arr[] = {1, 5, 5, 6, 21, 4, 8, 22, 5, 4, 4, 65, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << endl
         << dequeue(arr, &size);
    cout << endl
         << dequeue(arr, &size);
    cout << endl
         << dequeue(arr, &size);
}