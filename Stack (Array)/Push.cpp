#include<iostream>
using namespace std;


void display(int arr[],int n){
    cout << endl;
    for (int i = 0; i < n;i++)
        cout << arr[i] << " ";
}

void push(int element,int arr[],int *top,int mSize){

    if(*top<mSize)
        {
            for (int i = *top; i>0;i--)
                arr[i] = arr[i - 1];

            arr[0] = element;

            (*top)++;
        }
    else
        cout << "Stack Overflow"<<endl;
}

int main(){
    system("cls");

    int mSize = 10;
    int arr[mSize];
    int top = 0;

    display(arr,top);
    
    push(10,arr, &top, mSize);
    push(20,arr, &top, mSize);
    push(30,arr, &top, mSize);
    push(40,arr, &top, mSize);
    
    display(arr,top);
}