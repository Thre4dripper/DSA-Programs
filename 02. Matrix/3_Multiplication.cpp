#include <iostream>
using namespace std;

// Matrix Multiplication
void Multiply(int mat1[][5], int r1, int c1, int mat2[][4], int r2, int c2, int mat3[][4])
{

    if (c1 == r2)
    {
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
    }
    else
    {
        cout << "Cannot multiply the matrices" << endl;
    }
}

int main()
{

    int mat1[4][5] =
        {1, 2, 5, 6, 4,
         5, 2, 4, 8, 4,
         6, 2, 1, 3, 4,
         5, 4, 6, 8, 2};

    int mat2[5][4] =
        {5, 3, 4, 6,
         2, 4, 1, 5,
         2, 1, 4, 5,
         6, 3, 2, 5,
         7, 5, 8, 9};

    int mat3[4][4] = {0};

    Multiply(mat1, 4, 5, mat2, 5, 4, mat3);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << mat3[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}