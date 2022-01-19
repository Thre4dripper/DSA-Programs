#include <iostream>
using namespace std;

//function for sorting array using Shell Sort
int *ShellSort(int arr[], int n)
{
    int temp;
    int gap = n / 2;

    while (gap != 0)
    {
        for (int i = 0; i < n - gap + 1; i++)
        {
            for (int j = i + gap; j >= gap; j -= gap)
            {
                if (arr[j] < arr[j - gap])
                {
                    temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;
                }
            }
        }

        gap /= 2;
    }

    return arr;
}

int main()
{
    system("cls");
    int arr[] = {1, 2, 5, 63, 5, 4, 2, 0, 2, 5, 52, 63, 58, 41, 0, 63, 54, 0, 62, 85, 20, 41, 14, 20, 52, 5, 21, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int *ptr;

    ptr = ShellSort(arr, size);

    for (int i = 0; i < size; i++)
        cout << ptr[i] << " ";
}