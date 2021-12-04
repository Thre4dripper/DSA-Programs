#include <iostream>
//change order of matrix here
#define Dimens 5
using namespace std;

//function for clockwise spiral traversal
void SpiralClockwise(int arr[][Dimens], int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
    {
        cout << arr[0][i] << " ";
    }
    for (j = 1; j < row; j++)
    {
        cout << arr[j][col - 1] << " ";
    }
    for (i = col - 2; i >= 0; i--)
    {
        cout << arr[row - 1][i] << " ";
    }
    for (j = row - 2; j > 0; j--)
    {
        cout << arr[j][0] << " ";
    }
}

//function for anti-clockwise spiral traversal
void SpiralAntiClockwise(int arr[][Dimens], int row, int col)
{
    int i, j;
    for (i = col - 1; i >= 0; i--)
    {
        cout << arr[0][i] << " ";
    }
    for (j = 1; j < row; j++)
    {
        cout << arr[j][0] << " ";
    }
    for (i = 1; i < col; i++)
    {
        cout << arr[row - 1][i] << " ";
    }
    for (j = row - 2; j > 0; j--)
    {
        cout << arr[j][col - 1] << " ";
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

    cout << "\n Spiral Clockwise Traversal : ";
    SpiralClockwise(mat, Dimens, Dimens);
    cout << endl;

    cout << "\n Spiral Anti Clockwise Traversal : ";
    SpiralAntiClockwise(mat, Dimens, Dimens);
    return 0;
}