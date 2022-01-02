#include <iostream>
//change order of matrix here
#define Dimens 5
using namespace std;

int Trace(int mat[][Dimens], int r, int c)
{
    int sum = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            if (i == j)
                sum += mat[i][j];
    }
    return sum;
}

int main()
{

    int mat[][Dimens] =
        {1, 2, 5, 6, 4,
         5, 2, 4, 8, 4,
         6, 2, 1, 3, 4,
         5, 4, 6, 8, 2,
         1, 2, 3, 5, 6};

    int trace = Trace(mat, Dimens, Dimens);

    cout << "Trace: " << trace;
}