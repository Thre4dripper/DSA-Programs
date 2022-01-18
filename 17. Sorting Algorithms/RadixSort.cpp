#include <iostream>
#include <math.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

//function to insert element in radixBucket
void InsertBucket(int element, int index, node *radixBucket[])
{
    node *ptr = new node;
    ptr->data = element;
    ptr->next = NULL;

    node *p = radixBucket[index];
    if (p == NULL)
        radixBucket[index] = ptr;
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
    }
}

//function to remove element from radixBucket
int RemoveBucket(int index, node *radixBucket[])
{
    node *ptr = radixBucket[index];
    if (ptr == NULL)
        return -1;

    radixBucket[index] = radixBucket[index]->next;
    int element = ptr->data;
    delete ptr;

    return element;
}

//function for getting digits from maximum value in array
int MaxDigits(int arr[], int size)
{
    int max = arr[0];

    //getting maximum number
    for (int i = 1; i < size; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }

    int digits = 0;

    //counting its digits
    while (max != 0)
    {
        digits++;
        max /= 10;
    }

    return digits;
}

//function to sort array using Radix Sort
int *RadixSort(int arr[], int n)
{
    int i, j, k;

    node *radixBucket[10];

    //initializing with NULLs
    for (int i = 0; i < 10; i++)
        radixBucket[i] = NULL;

    //getting no of digits in maximum value
    int maxDigits = MaxDigits(arr, n);

    int receivedValue = 0, index = 0;

    //passes based of maxDigits
    for (int i = 1; i <= maxDigits; i++)
    {
        k = 0;

        //filling radix radixBucket
        for (int j = 0; j < n; j++)
        {
            index = (arr[j] % (int)pow(10, i)) / (int)pow(10, i - 1);
            InsertBucket(arr[j], index, radixBucket);
        }

        //extracting radixBucket array
        for (int j = 0; j < 10; j++)
        {
            receivedValue = RemoveBucket(j, radixBucket);

            //since radixBucket sort only works for +ve int
            //so -1 is excluded from radixBucket sorting
            if (receivedValue != -1)
            {
                arr[k++] = receivedValue;
                j--;
            }
        }
    }

    return arr;
}
int main()
{
    system("cls");

    int arr[] = {21, 5, 3, 6, 7, 4, 2, 23, 51, 146, 13, 64, 2, 6, 8, 84, 65, 32, 54, 6, 8, 21, 65, 99};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *ptr;

    ptr = RadixSort(arr, size);

    for (int i = 0; i < size; i++)
        cout << ptr[i] << " ";
}