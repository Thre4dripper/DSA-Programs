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

    int arr[] = {10, 20, 30, 40, 50};
    int mSize = sizeof(arr) / sizeof(arr[0]);

    cout << Peek(0, arr, mSize);
}