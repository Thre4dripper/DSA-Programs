#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

//for traverse and display all nodes of linked list
int display(node * top){
    int size = 0;
    cout << endl;
    while(top!=NULL){
        cout << top->data<<" ";
        top = top->next;
        size++;
    }
    return size;
}

int pop(node **top){
    int element=NULL;

    if(*top!=NULL){

        node *ptr = new node;
        ptr = *top;
        element = ptr->data;
        (*top) = (*top)->next;

        delete ptr;
    }
    else
        cout << "Stack Underflow"<<endl;
    return element;
}

int main(){
    system("cls");

    int size;
    node *head=new node;
    node *second = new node;
    node *third = new node;
    node *forth = new node;
    node *fifth = new node;

    node *top=head;

    head->data = 10;
    head->next =second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = forth;

    forth->data = 40;
    forth->next = fifth;

    fifth->data = 50;
    fifth->next = NULL;

    display(top);

    cout << endl<< pop(&top);

     display(top);

}