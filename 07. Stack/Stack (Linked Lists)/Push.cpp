#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

//for traverse and display all nodes of linked list
int display(Node * top){
    int size = 0;
    cout << endl;
    while(top!=NULL){
        cout << top->data<<" ";
        top = top->next;
        size++;
    }
    return size;
}

void push(int element,Node **top){
    Node *ptr = new Node;

    ptr->data = element;
    ptr->next = *top;

    *top = ptr;
}

int main(){
    system("cls");

    Node *top;

    top = NULL;

    display(top);
    push(10, &top);
    push(142, &top);
    push(15, &top);
    push(56, &top);
    display(top);
}