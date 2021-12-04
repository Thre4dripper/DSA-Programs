#include <iostream>
//change order of matrix here
#define Dimens 5
using namespace std;

//function for transpose
void Transpose(int mat[][Dimens])
{
    int temp[Dimens][Dimens];
    for (int i = 0; i < Dimens; i++)
    {
        for (int j = 0; j < Dimens; j++)
        {
            temp[i][j] = mat[j][i];
        }
    }
    for (int i = 0; i < Dimens; i++)
    {
        for (int j = 0; j < Dimens; j++)
        {
            mat[i][j] = temp[i][j];
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

    Transpose(mat);

    for (int i = 0; i < Dimens; i++)
    {
        for (int j = 0; j < Dimens; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}