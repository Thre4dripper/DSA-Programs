#include<iostream>
using namespace std;


int peek(int index,int arr[],int *mSize){

    if(index<*mSize)
        return arr[*mSize - index-1];
        else
            return NULL;
}

int main(){
    system("cls");

    int arr[]={1,5,5,6,21,4,8,22,5,4,4,65,12};
    int size = sizeof(arr)/sizeof(arr[0]);

    
    cout<<endl<<peek(6,arr, &size);
    
}