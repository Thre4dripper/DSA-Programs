#include <iostream>
using namespace std;

int peekStart(int arr[], int *mSize)
{

    if (*mSize == 0)
        return -1;
    return arr[0];
}

int peekEnd(int arr[], int *mSize)
{

    if (*mSize == 0)
        return -1;

    return arr[*mSize - 1];
}

int peekIndex(int index, int arr[], int *mSize)
{

    if (index < *mSize)
        return arr[*mSize - index - 1];
    else
        return -1;
}

int main()
{
    system("cls");

    int arr[] = {1, 5, 5, 6, 21, 4, 8, 22, 5, 4, 4, 65, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << endl
         << peekIndex(6, arr, &size);

    cout << endl
         << peekStart(arr, &size);

    cout << endl
         << peekEnd(arr, &size);
}