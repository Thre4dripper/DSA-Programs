#include <iostream>
using namespace std;

//Increament that index of Count Array which is eq to some element in Sorting Array
int *CountSort(int arr[], int n)
{
    int MAX = arr[0], i, j = 0;

    for (i = 0; i < n; i++)
        if (MAX < arr[i])
            MAX = arr[i];

    int count[MAX + 1];

    //initializing with 0
    for (i = 0; i <= MAX; i++)
        count[i] = 0;

    //filling count array
    for (i = 0; i < n; i++)
        count[arr[i]]++;

    //extracting count array
    for (i = 0; i <= MAX; i++)
    {
        if (count[i] > 0)
        {
            count[i]--;
            arr[j++] = i;
            i--;//for rescanning of duplicate elements
        }
    }

    return arr;
}
int main()
{
    system("cls");

    int arr[] = {2, 5, 7, 6, 3, 1, 45, 12, 56, 79, 6, 32, 54, 74, 32, 12, 84, 6, 1, 21, 96, 65, 54, 97, 6, 15, 32, 52};
    int size = sizeof(arr) / sizeof(arr[0]);

    int *ptr;

    ptr = CountSort(arr, size);

    for (int i = 0; i < size; i++)
        cout << ptr[i] << " ";
}