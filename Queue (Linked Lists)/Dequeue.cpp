#include<iostream>
using namespace std;

struct node{
    int data;
    node * next;
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

int dequeue(node **head){
    int element=NULL;
    if(head!=NULL){
        node *last = new node;
        last = *head;

        node *ptr;
        while (last->next!=NULL){
            ptr = last;
            last = last->next;
        }

        element = last->data;
        ptr->next = NULL;
        delete last;
    }
    else
        cout << "Queue Underflow"<<endl;
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

    node *top = head;
    node *last = fifth;
 
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

    size=display(head);
    cout << endl<< dequeue(&top);
    cout << endl<< dequeue(&top);
    cout << endl<< dequeue(&top);

}