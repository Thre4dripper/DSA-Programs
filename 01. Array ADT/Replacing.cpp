#include<iostream>

using namespace std;

void display(int arr[],int size){

    cout << endl;
    for(int i = 0; i < size;i++)
            cout << arr[i]<<" ";
}

//Definition for replace element from Start
int replacingFromStart(int element,int arr[],int size){
    int initElement;

    //size should be at least 1 for deletion
    if (size <= 0)
        return 0;

    else{
        initElement = arr[0];
        arr[0] = element;
    }
    return initElement;
}


//Definition for replace element from End
int replacingFromEnd(int element,int arr[],int size){

    int initElement;
    if(size<=0)
        return 0;

        else {
            initElement = arr[size - 1];
            arr[size - 1] = element;
        }
   

        return initElement;
}


//Definition for replace element from any index
int replacingFromIndex(int element,int index,int arr[],int size){

    int initElement;
    //index should also be valid
    if(size>0 && index<=size && index >= 0){
        initElement = arr[index];

        arr[index] = element;

        return initElement;
        }
    
    else
        return 0;
}

int main(){
    system("cls");

    int mSize = 12;

    int arr[mSize] = {2, 5, 6, 4, 8};
    int size = 5;

    display(arr, size);

    cout<<endl<<replacingFromIndex(45,1,arr, size);
    

    display(arr, size);
}