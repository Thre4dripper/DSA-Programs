#include<iostream>

using namespace std;

void display(int arr[],int size){

    cout << endl;
    for(int i = 0; i < size;i++)
            cout << arr[i]<<" ";
}

//Definition for insert element at Start
int insertAtStart(int element,int arr[],int size,int mSize){

//size should be at least 1 less than max size to insert an element
if(size>=mSize)
    return 0;

    else{

    for (int i = size; i >0;i--)
        arr[i] = arr[i-1];

        arr[0] = element;
    }
    return 1;
}


//Definition for insert element at End
int insertAtEnd(int element,int arr[],int size,int mSize){

    if(size>=mSize)
        return 0;
        else 
    arr[size] = element;

        return 1;
}


//Definition for insert element at any index
int insertAtIndex(int element,int index,int arr[],int size,int mSize){

    //index should also be valid
    if(size<=mSize && index<=size && index >= 0){
            for (int i = size; i >index;i--)
                arr[i] = arr[i - 1];

            arr[index] = element;

            return 1;
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

    size += insertAtIndex(7,4, arr, size, mSize);
    // size += insertAtIndex(45, arr, size, mSize);
    // size += insertAtIndex(56, arr, size, mSize);
    // size += insertAtIndex(24, arr, size, mSize);

    display(arr, size);
}