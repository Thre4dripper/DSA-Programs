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

int pop(Node **top){
    int element=NULL;

    if(*top!=NULL){

        Node *ptr = new Node;
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
    Node *head=new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *forth = new Node;
    Node *fifth = new Node;

    Node *top=head;

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