#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

//for traverse and display all nodes of linked list
int display(node * head){
    int size = 0;
    cout << endl;
    while(head!=NULL){
        cout << head->data<<" ";
        head = head->next;
        size++;
    }
    return size;
}

void push(int element,node **head){
    node *top = new node;

    top->data = element;
    top->next = *head;

    *head = top;
}

int main(){
    system("cls");

    node *head;

    head = NULL;

    display(head);
    push(10, &head);
    push(142, &head);
    push(15, &head);
    push(56, &head);
    display(head);
}