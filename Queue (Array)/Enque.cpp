#include<iostream>
using namespace std;


void display(int arr[],int n){
    cout << endl;
    for (int i = 0; i < n;i++)
        cout << arr[i] << " ";
}

void enqueue(int element,int arr[],int *front,int mSize){

    if(*front<mSize)
        {
            for (int i = *front; i>0;i--)
                arr[i] = arr[i - 1];

            arr[0] = element;

            (*front)++;
        }
    else
        cout << "Queue Overflow"<<endl;
}

int main(){
    system("cls");

    int mSize = 4;
    int arr[mSize];
    int front = 0;

    display(arr,front);
    
    enqueue(10,arr, &front, mSize);
    
    display(arr,front);
}