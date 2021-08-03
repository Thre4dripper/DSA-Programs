#include<iostream>
using namespace std;

//Compare two adjacent elements and swaps them acc to assecnding or descending order
int * BubbeSort(int arr[],int n){
    int temp = 0;

    for (int i = n-1; i >=0;i--){
        for (int j = 0; j <= i;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

        return arr;
}
int main(){
    system("cls");

    int arr[] = {21, 32,9, 12, 45, 23, 56, 1, 2, 5, 7, 8, 63, 45, 1, 2, 5, 89, 3, 5, 9, 4, 54};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *ptr;

    ptr = BubbeSort(arr, size);

    for (int i = 0; i < size;i++)
        cout << ptr[i] << " ";
}