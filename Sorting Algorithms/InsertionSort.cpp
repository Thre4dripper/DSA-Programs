#include<iostream>
using namespace std;

//Insert element in each left subarray checking whether a element is smaller or not
int* insertionSort(int arr[],int n){
    int temp;
    for (int i = 1; i < n;i++){
        for (int j = i; j > 0;j--){
            if(arr[j]<arr[j-1]){
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }

    return arr;
}


int main(){
    system("cls");
    int arr[] = {23, 45, 26, 12, 4, 98, 2, 14, 5, 8, 7, 2, 3, 1, 45, 65, 21, 78, 56, 23, 32};
    int size = sizeof(arr) / sizeof(arr[0]);

    int *ptr;

    ptr = insertionSort(arr, size);

    for (int i = 0; i < size;i++)
        cout << ptr[i]<<" ";

}