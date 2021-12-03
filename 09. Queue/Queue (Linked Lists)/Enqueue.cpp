#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

int display(node *front){
    int size=0;
    cout << endl;
    while (front!=NULL){
        cout << front->data<<" ";
        front = front->next;
        size++;
    }

    return size;
}
void enqueue(int element, node **front,node **rear){
    node *ptr = new node;

    ptr->data = element;
    ptr->next = NULL;
    if(*front==NULL){
        *front = *rear = ptr;
    }
    else{
        (*rear)->next = ptr;
        *rear = ptr;
    }
}

int main(){
    system("cls");
    node *front = NULL;
    node *rear = NULL;

    display(front);
    enqueue(10, &front, &rear);
    enqueue(20, &front, &rear);
    enqueue(30, &front, &rear);

    display(front);
}