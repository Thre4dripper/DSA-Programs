#include <iostream>
using namespace std;

//Increament that index of Count Array which is eq to some element in Sorting Array
int *CountSort(int arr[], int n)
{
    int MAX = arr[0], i, j = 0;

    for (i = 0; i < n; i++)
        if (MAX < arr[i])
            MAX = arr[i];

    int count[MAX];

    for (i = 0; i < MAX; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
        count[arr[i]]++;

    for (i = 0; i < MAX; i++)
    {
        if (count[i] > 0)
        {
            count[i]--;
            arr[j] = i;
            j++;
            i--;
        }
    }

    return arr;
}
int main()
{
    system("cls");

    int arr[] = {23, 45, 26, 12, 4, 98, 2, 14, 5, 8, 7, 2, 3, 1, 45, 65, 21, 78, 56, 23, 32};
    int size = sizeof(arr) / sizeof(arr[0]);

    int *ptr;

    ptr = CountSort(arr, size);

    for (int i = 0; i < size; i++)
        cout << ptr[i] << " ";
}