#include <iostream>
using namespace std;

void Merge(int arr[], int low, int mid, int high)
{
    int B[high+1];
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            B[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            B[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        B[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = arr[j];
        j++;
        k++;
    }

    for (int i = low; i <= high; i++)
        arr[i] = B[i];
}

//Splits Array upto 1 element's Sub array then Merge them by MergeSort
void MergeSort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

int main()
{
    system("cls");
    int arr[] = {2,6,4,98,41,41,56,45,65,65,9,87,7,5,63,4,8,6,1,6,54,4,8,6,2,4,98,2};
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort(arr, 0, size-1);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}