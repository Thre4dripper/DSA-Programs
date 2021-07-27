#include <iostream>
using namespace std;

int *SelectionSort(int arr[], int size)
{
    int temp;
    int min;
    int index;
    for (int i = 0; i < size - 1; i++)
    {
        index = i;
        min = arr[i];
        for (int j = i; j < size; j++)
            if (min > arr[j])
            {
                min = arr[j];
                index = j;
            }

        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;

    }

    // for (int i = 0; i < size;i++)
    //     cout << arr[i] << " ";
    return arr;
}

int main()
{
    system("cls");
    int arr[] = {2, 5, 3, 4, 9, 8, 7, 25, 21, 56, 4, 87, 6, 21, 23, 45, 87, 2, 16};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *ptr = arr;

    ptr = SelectionSort(arr, size);

    for (int i = 0; i < size;i++)
        cout << ptr[i] << " ";
}