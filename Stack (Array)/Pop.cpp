#include<iostream>
using namespace std;


int pop(int arr[],int *size){

    int element;
    if(*size!=0){
        element = arr[0];

        for (int i = 0; i <(*size)-1;i++)
            arr[i] = arr[i + 1];

        arr[(*size) - 1] = 0;
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
    cout<<endl<<pop(arr, &size);
    cout<<endl<<pop(arr, &size);
    cout<<endl<<pop(arr, &size);
    
}