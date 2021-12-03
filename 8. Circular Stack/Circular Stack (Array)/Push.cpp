#include <iostream>
using namespace std;

//function to display whole Stack
void display(int arr[], int f, int r, int mSize)
{
    cout << endl
         << "Stack->";
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

//definition for inertion of elements in Stack
void Push(int element, int arr[], int *f, int *r, int mSize)
{

    //special case when starting filling Stack
    if (*f == -1)
    {
        (*f) = 0;
        (*r) = 1;
        arr[*f] = element;
    }
    else
    { //first stored then increment 'r'
        if (*r != *f)
        {
            arr[*r] = element;
            (*r) = (*r + 1) % mSize;
        }
        else
        {
            arr[*r] = element;
            (*r) = (*r + 1) % mSize;
            (*f) = (*f + 1) % mSize;
        }
    }
}

int main()
{
    system("cls");

    int mSize = 3;
    int arr[mSize];

    int f = -1, r = -1;
    display(arr, f, r, mSize);

    Push(10, arr, &f, &r, mSize);
    Push(20, arr, &f, &r, mSize);
    Push(30, arr, &f, &r, mSize);
    Push(40, arr, &f, &r, mSize);
    Push(50, arr, &f, &r, mSize);


    display(arr, f, r, mSize);
}