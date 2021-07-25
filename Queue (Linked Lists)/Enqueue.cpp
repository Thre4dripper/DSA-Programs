#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

int display(node *top){
    int size=0;
    cout << endl;
    while (top!=NULL){
        cout << top->data<<" ";
        top = top->next;
        size++;
    }

    return size;
}
void enqueue(int element, node **top){
    node *ptr = new node;

    ptr->data = element;
    ptr->next = *top;

    *top = ptr;
}

int main(){
    system("cls");
    node *top = NULL;

    display(top);
    enqueue(10, &top);
    
    enqueue(20, &top);
    
    enqueue(30, &top);
    
    enqueue(45, &top);
    display(top);
}