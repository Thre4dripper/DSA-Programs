#include <iostream>
using namespace std;

//function for deleting element from start
int dequeueStart(int arr[], int *size)
{

    int element;
    if (*size != 0)
    {
        element = arr[0];
        for (int i = 0; i < *size - 1; i++)
            arr[i] = arr[i + 1];
        (*size)--;
    }
    else
        cout << "Queue Underflow" << endl;
    return element;
}

//function for deleting element from end
int dequeueEnd(int arr[], int *size)
{

    int element;
    if (*size != 0)
    {
        element = arr[*size - 1];
        (*size)--;
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
         << dequeueStart(arr, &size);
    cout << endl
         << dequeueStart(arr, &size);
    cout << endl
         << dequeueStart(arr, &size);
    cout << endl
         << dequeueEnd(arr, &size);
    cout << endl
         << dequeueEnd(arr, &size);
}