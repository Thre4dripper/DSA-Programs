#include <iostream>
#define Dimens 5
using namespace std;

//function for subtract two matrices of same dimensions
void Multiply(int mat1[][Dimens], int r1, int c1, int mat2[][Dimens], int r2, int c2, int mat3[][Dimens])
{
    if (r1 == r2 && c1 == c2)
    {
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
                mat3[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    else
        cout << "\nIncompatible Dimensions\n";
}

int main()
{

    int mat1[][Dimens] =
        {1, 2, 5, 6, 4,
         5, 2, 4, 8, 4,
         6, 2, 1, 3, 4,
         5, 4, 6, 8, 2,
         1, 2, 3, 5, 6};

    int mat2[][Dimens] =
        {5, 3, 4, 6, 7,
         2, 4, 1, 5, 6,
         2, 1, 4, 5, 8,
         6, 3, 2, 5, 4,
         7, 5, 8, 9, 6};

    int mat3[][Dimens] = {0};

    Multiply(mat1, Dimens, Dimens, mat2, Dimens, Dimens, mat3);

    if (mat3 != NULL)
        for (int i = 0; i < Dimens; i++)
        {
            for (int j = 0; j < Dimens; j++)
                cout << mat3[i][j] << " ";
            cout << endl;
        }
}