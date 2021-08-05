#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

void traverse(node *head){

    node *ptr = new node;
    ptr = head;

if(ptr!=NULL)
    do{
        cout << ptr->data << " ";
        ptr = ptr->next;

    } while(ptr != head);
    else
        cout << "Empty Linked List" <<endl;
}
int main(){
    system("cls");

    node *head = new node;
    node *second = new node;
    node *third = new node;
    node *forth = new node;
    node *fifth = new node;   

    head->data = 10;
    head->next = second;

    second->data=20;
    second->next = third;

    third->data = 30;
    third->next=forth;

    forth->data = 40;
    forth->next = fifth;

    fifth->data = 50;
    fifth->next = head;

    
    traverse(head);
}