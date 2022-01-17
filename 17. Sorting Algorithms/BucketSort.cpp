#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

//function to insert element in bucket
void InsertBucket(int element, node *bucket[])
{
    node *ptr = new node;
    ptr->data = element;
    ptr->next = NULL;

    node *p = bucket[element];
    if (p == NULL)
        bucket[element] = ptr;
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
    }
}

//function to remove element from bucket
node *RemoveBucket(int index, node *bucket[])
{
    node *ptr = bucket[index];
    if (ptr == NULL)
        return NULL;

    bucket[index] = bucket[index]->next;

    return ptr;
}

//function to Sort array using bucket sort
int *BucketSort(int arr[], int n)
{
    int MAX = arr[0], i, j = 0;

    for (i = 0; i < n; i++)
    {
        if (MAX < arr[i])
            MAX = arr[i];
    }

    node *bucket[MAX + 1];

    //initializing with NULLs
    for (int i = 0; i <= MAX; i++)
        bucket[i] = NULL;

    // //filling bucket array
    for (int i = 0; i < n; i++)
        InsertBucket(arr[i], bucket);

    node *p = NULL;
    //extracting bucket array
    for (int i = 0; i <= MAX; i++)
    {
        p = RemoveBucket(i, bucket);
        if (p != NULL)
        {
            arr[j++] = p->data;
            i--; //for rescanning of duplicate elements
        }
    }

    return arr;
}

int main()
{
    system("cls");

    int arr[] = {5, 12, 31, 14, 4, 12, 5, 21, 6, 4, 8, 15, 42, 12, 56, 32, 45, 87, 32, 24, 64, 5, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *ptr;

    ptr = BucketSort(arr, size);

    for (int i = 0; i < size; i++)
        cout << ptr[i] << " ";
}