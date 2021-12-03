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

//definition for inertion of elements in queue
void Enqueue(int element, int arr[], int *f, int *r, int mSize)
{
    //special case when starting filling queue
    if (*f == -1)
    {
        *f = 0;
        *r = 1;
        arr[*f] = element;
    }
    else
    { //first stored then increment 'r'
        if (*r != *f)
        {
            arr[*r] = element;
            *r = (*r + 1) % mSize;
        }
        else
            cout << "Queue Full" << endl;
    }
}

int main()
{
    system("cls");
    int mSize = 5;
    int arr[mSize];
    //at staring both pointers are -1
    int f = -1, r = -1;

    display(arr, f, r, mSize);

    Enqueue(10, arr, &f, &r, mSize);
    Enqueue(20, arr, &f, &r, mSize);
    Enqueue(30, arr, &f, &r, mSize);
    Enqueue(40, arr, &f, &r, mSize);
    Enqueue(50, arr, &f, &r, mSize);

    display(arr, f, r, mSize);
}