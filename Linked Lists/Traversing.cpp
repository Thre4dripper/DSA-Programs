#include<iostream>
using namespace std;

struct node{
    int data;
    node * link;
};


void Traverse(node *head){
    
    while(head->link!=NULL){
        cout << head->data<<" ";
        head = head->link;
    }
}

int main(){
    system("cls");

    node *head=new node;
    node *second = new node;
    node *third = new node;
    node *forth = new node;
    node *fifth = new node;

    head->data = 10;
    head->link =second;

    second->data = 20;
    second->link = third;

    third->data = 30;
    third->link = forth;

    forth->data = 40;
    forth->link = fifth;

    fifth->data = 50;
    fifth->link = NULL;

    Traverse(head);
}