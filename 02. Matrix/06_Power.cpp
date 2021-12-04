#include <iostream>
//change order of matrix here
#define Dimens 5

using namespace std;

// Matrix Multiplication
void Multiply(int mat1[][Dimens], int r1, int c1, int mat2[][Dimens], int r2, int c2)
{

    if (c1 == r2)
    {
        int mat3[r1][c2];
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                mat3[i][j] = 0;
                for (int k = 0; k < c1; k++)
                {
                    mat3[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }

        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                mat1[i][j] = mat3[i][j];
            }
        }
    }
    else
    {
        cout << "Cannot multiply the matrices" << endl;
    }
}

// Matrix Power
void Power(int a[][Dimens], int p)
{
    int b[Dimens][Dimens];
    for (int i = 0; i < Dimens; i++)
    {
        for (int j = 0; j < Dimens; j++)
        {
            b[i][j] = a[i][j];
        }
    }
    for (int i = 1; i < p; i++)
        Multiply(a, Dimens, Dimens, b, Dimens, Dimens);
}
int main()
{
    int mat[][Dimens] =
        {1, 2, 5, 6, 4,
         5, 2, 4, 8, 4,
         6, 2, 1, 3, 4,
         5, 4, 6, 8, 2,
         1, 2, 3, 5, 6};

    Power(mat, 3);

    for (int i = 0; i < Dimens; i++)
    {
        for (int j = 0; j < Dimens; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}