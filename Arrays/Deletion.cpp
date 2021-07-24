#include<iostream>

using namespace std;

void display(int arr[],int size){

    cout << endl;
    for(int i = 0; i < size;i++)
            cout << arr[i]<<" ";
}

//Definition for delete element from Start
int deletionFromStart(int arr[],int size){

    int element;
    //size should be at least 1 for deletion
    if (size <= 0)
        return 0;

    else{
        element = arr[0];

        for (int i = 0; i < size; i++)
            arr[i] = arr[i + 1];

        arr[size - 1] = 0;
    }
    return element;
}


//Definition for deletion element from End
int deletionFromEnd(int arr[],int size){

    int element;
    if(size<=0)
        return 0;

        else {
            element = arr[size - 1];
            arr[size-1] = 0;
        }
   

        return element;
}


//Definition for deletion element from any index
int deletionFromIndex(int index,int arr[],int size){

    int element;
    //index should also be valid
    if(size>0 && index<=size && index >= 0){
        element = arr[index];

        for (int i = index; i < size; i++)
            arr[i] = arr[i + 1];

        arr[size-1] = 0;

        return element;
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

    cout<<endl<<deletionFromIndex(2,arr, size--);
    

    display(arr, size);
}