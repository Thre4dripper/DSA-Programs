#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

//for traverse and display all nodes of linked list
int display(Node * head){
    int size = 0;
    cout << endl;
    while(head!=NULL){
        cout << head->data<<" ";
        head = head->next;
        size++;
    }
    return size;
}

int peek(int index,Node *head,int *size){
    int element=NULL;

    if(index<*size){
        Node *top = new Node;
        top = head;
        for (int i = 0; i < index && top->next!=NULL;i++){
            top = top->next;
        }

        element = top->data;
    }
    else
        cout << "Index greater than size"<<endl;
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

    cout << endl << peek(4, head, &size);
}