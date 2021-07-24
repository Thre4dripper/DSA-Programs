#include<iostream>>
using namespace std;

int linearSearch(int element, int arr[], int size){
    bool found=false;
    int i;
    for (i = 0; i < size;i++)
        if(element==arr[i]){
            found = true;
            break;
        }
            
    if(found)
        return i;
    else 
        return -1;
}

int main(){
    system("cls");

    int arr[10] = {1, 2, 5, 7, 6, 8, 5, 4, 1, 9};
    int size = 10;

    cout<<linearSearch(4,arr,size);
}