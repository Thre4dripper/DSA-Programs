#include<iostream>>
using namespace std;

int binarySearch(int element, int arr[], int size){
    bool found=false;
    int mid, first = 0, last = size-1;

    while(first<last){
        mid = (first + last) / 2;

        if(element==arr[mid]){
            found = true;
            break;
        }
        else if(element<mid){
            last = mid - 1;
        }
        else if(element>mid){
            first = mid+1;
        }
    }

    if(found)
        return mid;
    else
        return -1;
}

int main(){
    system("cls");

    int size = 10;
    int arr[size] = {1,3,5,9,10,15,19,20,23,24};
    

    cout<<binarySearch(19,arr,size);
}