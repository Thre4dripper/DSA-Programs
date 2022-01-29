#include<iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
};

int search(int element,Node *head){
    bool found = false;
    int index = 0;

    while(head!=NULL){
        if(element==head->data){
            found = true;
            break;
        }
        head = head->next;
        index++;
    }
    if(found)
        return index;
    else
        return -1;
}

int main(){
    system("cls");

    int size;
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

    cout << search(30, head);
}