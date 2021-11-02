#include<iostream>
using namespace std;

//function to check stack in empty or not
int isEmpty(int *size){
    if(*size==0)
        return 1;
    else
        return 0;
}

int main(){
    system("cls");

    int arr[]={1,5,5,6,21,4,8,22,5,4,4,65,12};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    cout<<endl<<isEmpty(&size);
    
}