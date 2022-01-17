#include <iostream>
using namespace std;

//function to display heap
void display(int arr[], int size)
{
    //arr indexing is from 1..size
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

//function to convert normal array into Min Heap
void MinHeapify(int arr[], int size)
{
    for (int i = size; i > 0; i--)
    {
        int j = i;
        int k = 2 * j;
        while (k <= size)
        {
            if (arr[k] < arr[k + 1])
            {
                if (arr[k] < arr[j])
                    swap(&arr[j], &arr[k]);
                j = k;
            }
            else
            {
                if (arr[k + 1] < arr[j])
                    swap(&arr[j], &arr[k + 1]);
                j = k + 1;
            }

            k = 2 * j;
        }
    }
}

int main()
{
    system("cls");

    int arr[] = {0, 21, 25, 12, 18, 24, 16, 31};
    int size = sizeof(arr) / sizeof(arr[0]) - 1;

    cout << "Array: ";
    display(arr, size);

    MaxHeapify(arr, size);
    cout << "\n\nMax Heap: ";
    display(arr, size);

    MinHeapify(arr, size);
    cout << "\n\nMin Heap: ";
    display(arr, size);
}