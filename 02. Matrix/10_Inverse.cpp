#include <iostream>
#include <math.h>
//change order of matrix here
#define Dimens 5
using namespace std;

//function to find determinant of matrix
int determinant(float a[][Dimens], int n)
{
    int det = 0;
    if (n == 1)
        return a[0][0];
    if (n == 2)
        return a[0][0] * a[1][1] - a[1][0] * a[0][1];
    else
    {
        float sub_mat[Dimens][Dimens];
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

//function to find minor of matrix
int Minor(float matrix[][Dimens], int n, int i, int j)
{
    float submatrix[Dimens][Dimens];
    int k = 0, l = 0;
    for (int row = 0; row < n; row++)
    {
        if (row != i)
        {
            for (int col = 0; col < n; col++)
            {
                if (col != j)
                {
                    submatrix[k][l] = matrix[row][col];
                    l++;
                }
            }
            l = 0;
            k++;
        }
    }
    return determinant(submatrix, n - 1);
}

//function to find adjoint of matrix
void Adjoint(float matrix[][Dimens], int n)
{
    int adj[Dimens][Dimens];
    int sign = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int minor = Minor(matrix, n, i, j);
            adj[j][i] = sign * minor;
            sign = -sign;
        }
        sign = 1;
    }
}

//function to find inverse of matrix
void Inverse(float matrix[][Dimens], int n)
{
    int det = determinant(matrix, n);
    if (det == 0)
    {
        cout << "Inverse does not exist";
        return;
    }
    Adjoint(matrix, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = matrix[i][j] / det;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    float mat[][Dimens] =
        {1, 2, 5,
         5, 2, 4,
         6, 2, 5};

    Inverse(mat, Dimens);
}