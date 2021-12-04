#include <iostream>
//change order of matrix here
#define Dimens 5
using namespace std;

//function for cockwise rotation of matrix
void RotationClockwise(int arr[][Dimens], int n)
{
    int temp[Dimens][Dimens];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = arr[n - 1 - j][i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = temp[i][j];
        }
    }
}

//function for anticlockwise rotation of matrix
void RotationAntiClockwise(int arr[][Dimens], int n)
{
    int temp[Dimens][Dimens];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = arr[j][n - i - 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = temp[i][j];
        }
    }
}

int main()
{
    int mat[][Dimens] =
        {1, 2, 5, 6, 4,
         5, 2, 4, 8, 4,
         6, 2, 1, 3, 4,
         5, 4, 6, 8, 2,
         1, 2, 3, 5, 6};

    RotationClockwise(mat, Dimens);

    cout << "\nRotated Clockwise" << endl;
    for (int i = 0; i < Dimens; i++)
    {
        for (int j = 0; j < Dimens; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    RotationAntiClockwise(mat, Dimens);

    cout << "\nRotated Anti Clockwise" << endl;
    for (int i = 0; i < Dimens; i++)
    {
        for (int j = 0; j < Dimens; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}