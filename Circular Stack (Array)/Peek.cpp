#include <iostream>
using namespace std;

int Peek(int index, int arr[], int n)
{
    if (index < n && index >= 0)
        return arr[index];
    else
        cout << "Invalid Index" << endl;

    return 0;
}

int main()
{
    system("cls");

    int arr[] = {10, 23, 45, 32, 54};
    int mSize = sizeof(arr) / sizeof(arr[0]);

    cout << Peek(4, arr, mSize);
}