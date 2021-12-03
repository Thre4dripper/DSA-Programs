#include <iostream>
using namespace std;

//Splits Array such that all the smaller elements will be on one side 
//and larger on another of a given element
void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[low];
        int i = low + 1;
        int j = high;
        int temp;

        while (i <= j)
        {

            while (arr[i] <= pivot)
                i++;

            while (arr[j] > pivot)
                j--;

            if (i <= j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;

        QuickSort(arr, 0, j - 1);
        QuickSort(arr, j + 1, high);
    }
}

int main()
{
    system("cls");
    int arr[] = {45,4,64,15,41,94,1,32,54,65,8,98,87,5,1,2,63,6,88,45,6,94,97,54,12,65,9};
    int size = sizeof(arr) / sizeof(arr[0]);

    QuickSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}