#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

//function to insert element in bucket
void InsertBucket(int element, Node *bucket[])
{
    Node *ptr = new Node;
    ptr->data = element;
    ptr->next = NULL;

    Node *p = bucket[element];
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
int RemoveBucket(int index, Node *bucket[])
{
    Node *ptr = bucket[index];
    if (ptr == NULL)
        return -1;

    bucket[index] = bucket[index]->next;
    int element = ptr->data;
    delete ptr;

    return element;
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

    Node *bucket[MAX + 1];

    //initializing with NULLs
    for (int i = 0; i <= MAX; i++)
        bucket[i] = NULL;

    // //filling bucket array
    for (int i = 0; i < n; i++)
        InsertBucket(arr[i], bucket);

    int receivedValue = 0;
    //extracting bucket array
    for (int i = 0; i <= MAX; i++)
    {
        receivedValue = RemoveBucket(i, bucket);

        //since bucket sort only works for +ve int so -1 is excluded from bucket sorting
        if (receivedValue != -1)
        {
            arr[j++] = receivedValue;
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