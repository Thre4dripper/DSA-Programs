#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

void TraverseForward(node * head){

    cout << endl;

    while(head!=NULL){
        cout << head->data<<" ";
        head = head->next;
    }
}

void TraverseBackward(node * tail){

    cout << endl;

    while(tail!=NULL){
        cout << tail->data<<" ";
        tail = tail->prev;
    }
}


int main(){
    system("cls");
    node *head=new node;
    node *second=new node;
    node *third=new node;
    node *forth=new node;
    node *fifth=new node;

    head->data = 10;
    head->prev = NULL;
    head->next = second;

    second->data = 20;
    second->prev = head;
    second->next = third;

    third->data = 30;
    third->prev = second;
    third->next = forth;

    forth->data = 40;
    forth->prev = third;
    forth->next = fifth;

    fifth->data = 50;
    fifth->prev = forth;
    fifth->next = NULL;

    TraverseForward(head);
    TraverseBackward(fifth);
}