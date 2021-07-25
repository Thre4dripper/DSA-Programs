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

int pop(node **head){
    int element=NULL;

    if(*head!=NULL){
        
        node *top = new node;
        top=(*head);

        element=(*head)->data;
        (*head) = (*head)->next;

        delete top;
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

    display(head);

    cout << endl << pop(&head);
    display(head);
    cout << endl << pop(&head);
    display(head);
    cout << endl << pop(&head);
    display(head);

}