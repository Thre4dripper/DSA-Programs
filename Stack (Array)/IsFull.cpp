#include<iostream>
using namespace std;

//function to check stack in full or not
int isFull(int *size,int *mSize){
    if(*size==*mSize)
        return 1;
    else
        return 0;
}

int main(){
    system("cls");

    int mSize = 13;
    int arr[]={1,5,5,6,21,4,8,22,5,4,4,65,12};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<endl<<isFull(&size,&mSize);
    
}