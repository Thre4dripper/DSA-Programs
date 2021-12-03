#include <iostream>
#define Dimens 5
using namespace std;

//function to find determinant of matrix
int determinant(int a[][Dimens], int n)
{
    int det = 0;
    if (n == 1)
        return a[0][0];
    else
    {
        int sub_mat[Dimens][Dimens];
        int sign = 1;
        for (int i = 0; i < n; i++)
        {
            int j = 0;
            for (int row = 1; row < n; row++)
            {
                int k = 0;
                for (int col = 0; col < n; col++)
                {
                    if (col == i)
                        continue;
                    sub_mat[row - 1][k] = a[row][col];
                    k++;
                }
            }
            det += sign * a[0][i] * determinant(sub_mat, n - 1);
            sign = -sign;
        }
    }
    return det;
}

int main()
{
    int mat[][Dimens] =
        {1, 2, 5, 6, 4,
         5, 2, 4, 8, 4,
         6, 2, 1, 3, 4,
         5, 4, 6, 8, 2,
         1, 2, 3, 5, 6};

    cout << determinant(mat, Dimens);
}