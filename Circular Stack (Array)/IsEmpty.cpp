#include <iostream>
using namespace std;

///function for checking circular stack is empty or not
int IsEmpty(int arr[], int f, int r, int n)
{
    if (f == -1)
        return 1;
    else
        return 0;
}

int main()
{
    system("cls");

    int arr[] = {10, 23, 45, 32, 54};
    int mSize = sizeof(arr) / sizeof(arr[0]);

    //r is for insertion at end and overwrites succeeding values
    //f follows r in that case
    //see POP for more detail about is empty
    int f = 4, r = 4; //at 4th index right now

    cout << IsEmpty(arr, f, r, mSize);
}