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


//definition for removing elements in queue
int Pop(int arr[], int *f, int *r, int mSize)
{
    int element;

    if (*f == -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        //for Stack 'r' will restrace its path backwards, But first decrease then remove
        (*r)--;
        if (*r == -1)
            (*r) = mSize - 1;

        element = arr[*r];
        arr[*r] = 0;

        if (*f == *r)
            (*f) = (*r) = -1;
    }

    return element;
}

int main()
{
    system("cls");

    int arr[]={10,23,45,32,54};
    int mSize = sizeof(arr)/sizeof(arr[0]);

    int f = 0, r = 0;//r has completed one loop after insertion
    display(arr, f, r, mSize);


    cout << endl
         << Pop(arr, &f, &r, mSize);
    cout << endl
         << Pop(arr, &f, &r, mSize);
    cout << endl
         << Pop(arr, &f, &r, mSize);

    display(arr, f, r, mSize);
}