#include<iostream>
using namespace std;


int pop(int arr[],int *size){

    int element;
    if(*size!=0){
        element = arr[*size-1];
        (*size)--;
    }
    else
        cout << "Stack Underflow"<<endl;
    return element;
}

int main(){
    system("cls");

    int arr[]={1,5,5,6,21,4,8,22,5,4,4,65,12};
    int size = sizeof(arr)/sizeof(arr[0]);

    
    cout<<endl<<pop(arr, &size);
    
}