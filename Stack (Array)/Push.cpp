#include<iostream>
using namespace std;


void display(int arr[],int n){
    cout << endl;
    for (int i = 0; i < n;i++)
        cout << arr[i] << " ";
}

void push(int element,int arr[],int *size,int mSize){

    if(*size<mSize)
        arr[(*size)++] = element;
    else
        cout << "Stack Overflow"<<endl;
}

int main(){
    system("cls");

    int mSize = 10;
    int arr[mSize];
    int size = 0;

    display(arr,size);
    
    push(10,arr, &size, mSize);
    
    display(arr,size);
}