#include <iostream>
using namespace std;

//function to display heap
void display(int arr[], int size)
{
    //arr indexing is from 1..size
    for (int i = 1; i <= size; i++)
        cout << arr[i] << " ";
}

//function to insert element in max heap
void InsertMaxHeap(int element, int arr[], int *size, int mSize)
{
    if (*size >= mSize)
    {
        cout << "Size Overflow!!!" << endl;
        return;
    }

    int i = *size + 1;
    while (i > 0)
    {
        if (element < arr[i / 2])
            break;

        arr[i] = arr[i / 2];
        i /= 2;
    }
    arr[i] = element;
    (*size)++;
}

//function to insert element in min heap
void InsertMinHeap(int element, int arr[], int *size, int mSize)
{
    if (*size >= mSize)
    {
        cout << "Size Overflow!!!" << endl;
        return;
    }

    int i = *size + 1;
    while (i > 1)
    {

        if (element > arr[i / 2])
            break;

        arr[i] = arr[i / 2];
        i /= 2;
    }
    arr[i] = element;
    (*size)++;
}

int main()
{
    system("cls");

    int mSize = 6;
    int arr[mSize + 1];
    int size = 0;

    InsertMinHeap(10, arr, &size, mSize);
    InsertMinHeap(5, arr, &size, mSize);
    InsertMinHeap(20, arr, &size, mSize);
    InsertMinHeap(15, arr, &size, mSize);
    InsertMinHeap(21, arr, &size, mSize);
    InsertMinHeap(22, arr, &size, mSize);

    display(arr, size);
}