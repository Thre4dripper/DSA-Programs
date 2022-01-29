#include<iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
};


void Traverse(Node *head){
    
    while(head!=NULL){
        cout << head->data<<" ";
        head = head->next;
    }
}

int main(){
    system("cls");

    Node *head=new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *forth = new Node;
    Node *fifth = new Node;

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

    Traverse(head);
}