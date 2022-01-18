#include <iostream>
using namespace std;

//function for swapping two variables
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//function to convert normal array into Max Heap
void MaxHeapify(int arr[], int size)
{
    for (int i = size; i > 0; i--)
    {
        int j = i;
        int k = 2 * j;
        while (k <= size)
        {
            if (arr[k] > arr[k + 1])
            {
                if (arr[k] > arr[j])
                    swap(&arr[j], &arr[k]);
                j = k;
            }
            else
            {
                if (arr[k + 1] > arr[j])
                    swap(&arr[j], &arr[k + 1]);
                j = k + 1;
            }

            k = 2 * j;
        }
    }
}

//function to remove element from max heap
void RemoveMaxHeap(int arr[], int size)
{
    if (size == 1)
    {
        cout << "Heap is Empty!!!" << endl;
        return;
    }

    int element = arr[1];
    arr[1] = arr[size];
    size--;

    int i = 1;
    int j = 2 * i;

    while (j <= size)
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
    arr[size + 1] = element;
}

//function for sorting array using heap sort (Max Heap)
int *HeapSort(int arr[], int n)
{
    MaxHeapify(arr, n);

    for (int i = n; i > 1; i--)
        RemoveMaxHeap(arr, i);

    return arr;
}

int main()
{
    system("cls");
    int arr[] = {0, 52, 52, 20, 4, 8, 6, 3, 54, 85, 3, 52, 8, 98, 6, 2, 41, 7, 12, 20, 5, 0, 25, 4};
    int size = sizeof(arr) / sizeof(arr[0]) - 1;
    int *ptr;

    ptr = HeapSort(arr, size);

    for (int i = 0; i < size; i++)
        cout << ptr[i] << " ";

    // for sorting in descending order, use Min heap operations
}