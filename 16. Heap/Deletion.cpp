#include <iostream>
using namespace std;

//function to display heap
void display(int arr[], int size)
{
    //array indexing is from 1..size
    for (int i = 1; i <= size; i++)
        cout << arr[i] << " ";
}

//function for swapping two variables
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//function to remove element from max heap
int RemoveMaxHeap(int arr[], int *size)
{
    if ((*size) == 1)
    {
        cout << "Heap is Empty!!!" << endl;
        return -1;
    }

    int element = arr[1];
    arr[1] = arr[*size];
    (*size)--;

    int i = 1;
    int j = 2 * i;

    while (j <= *size)
    {
        if (arr[j] > arr[j + 1])
        {
            if (arr[j] > arr[i])
                swap(&arr[i], &arr[j]);
            i = j;
        }
        else
        {
            if (arr[j + 1] > arr[i])
                swap(&arr[i], &arr[j + 1]);
            i = j + 1;
        }

        j = 2 * i;
    }

    return element;
}

//function to remove element from min heap
int RemoveMinHeap(int arr[], int *size)
{
    if ((*size) == 1)
    {
        cout << "Heap is Empty!!!" << endl;
        return -1;
    }

    int element = arr[1];
    arr[1] = arr[*size];
    (*size)--;

    int i = 1;
    int j = 2 * i;

    while (j <= *size)
    {
        if (arr[j] < arr[j + 1])
        {
            if (arr[j] < arr[i])
                swap(&arr[i], &arr[j]);
            i = j;
        }
        else
        {
            if (arr[j + 1] < arr[i])
                swap(&arr[i], &arr[j + 1]);
            i = j + 1;
        }

        j = 2 * i;
    }

    return element;
}

int main()
{
    system("cls");

    int maxHeap[] = {0, 22, 21, 20, 5, 15, 10, 19};
    int size;

    //heap starts from index 1, so size is 1 less than original size
    size = sizeof(maxHeap) / sizeof(maxHeap[0]) - 1;

    cout << "Removed Value: " << RemoveMaxHeap(maxHeap, &size) << endl;
    cout << "Removed Value: " << RemoveMaxHeap(maxHeap, &size) << endl;
    cout << "Removed Value: " << RemoveMaxHeap(maxHeap, &size) << endl;
    cout << "Max heap: ";
    display(maxHeap, size);

    int minHeap[] = {0, 5, 10, 20, 15, 21, 22, 25};
    //heap starts from index 1, so size is 1 less than original size
    size = sizeof(minHeap) / sizeof(minHeap[0]) - 1;

    cout << endl
         << endl;
    cout << "Removed Value: " << RemoveMinHeap(minHeap, &size) << endl;
    cout << "Removed Value: " << RemoveMinHeap(minHeap, &size) << endl;
    cout << "Removed Value: " << RemoveMinHeap(minHeap, &size) << endl;
    cout << "Min heap: ";
    display(minHeap, size);
}