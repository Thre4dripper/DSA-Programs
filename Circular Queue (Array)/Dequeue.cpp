#include <iostream>
using namespace std;

//function to display whole queue
void display(int arr[], int f, int r, int mSize)
{
    cout << endl
         << "Queue->";
    if (f != -1)
    { //loop at least one time
        do
        {
            cout << arr[f] << " ";
            f = (f + 1) % mSize;

        } while (f != r); //to counter this condition
        //cause f==r is condition for both FULL and EMPTY queue
    }
}

//definition for removing elements in queue
int remove(int arr[], int *f, int *r, int mSize)
{
    int element;
    if (*f == -1)
    {
        cout << "Queue Empty" << endl;
    }
    else
    {
        //first remove then increment 'f'
        element = arr[*f];
        arr[*f] = 0;
        *f = (*f + 1) % mSize;

        if (*f == *r)
            *f = *r = -1;

        //cout << *f;
    }
    return element;
}

int main()
{
    system("cls");

    int arr[] = {10, 20, 30, 40, 50};
    int mSize = sizeof(arr) / sizeof(arr[0]);
    int f = 0, r = 0; //r has completed one loop after insertion

    display(arr, f, r, mSize);

    remove(arr, &f, &r, mSize);
    remove(arr, &f, &r, mSize);
    remove(arr, &f, &r, mSize);
    remove(arr, &f, &r, mSize);
    //remove(arr, &f, &r, mSize);

    display(arr, f, r, mSize);
}