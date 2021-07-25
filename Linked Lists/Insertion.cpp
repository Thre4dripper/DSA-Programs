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

//definition for insert element at start of linked list
node * insertAtStart(int element, node *head){

    node *ptr = new node;
    ptr->data = element;
    ptr->next = head;

    return ptr;
}

//definition for insert element at end of linked list
node * insertAtEnd(int element, node * head){
    node *ptr = new node;
    ptr->data = element;
    ptr->next = NULL;

    node *p = head;

    //only last node has next as NULL
    while(p->next!=NULL)
        p = p->next;

    p->next = ptr;

    return head;
}

//definition for insert element at an index of linked list
node * insertAtIndex(int element,int index,node * head,int size){
    node *ptr = new node;
    ptr->data = element;

    //scenario will be diff for '0' index (very begenning)
    if(index==0){
        ptr->next = head;
        head = ptr;
    }
    //for indexes smaller than linked list size  
     else if(index<=size){
        node *p=head;

        for (int i = 0;i<index-1 && p->next!=NULL;i++){
            p = p->next;
        }

        ptr->next = p->next;
        p->next = ptr;
    }
    else
        cout << "Index greater than Linked list size"<<endl;

    return head;
}

int main(){
    system("cls");

    node *head=new node;
    node *second = new node;
    node *third = new node;

    head->data = 10;
    head->next =second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    int size=display(head);

    head = insertAtIndex(40,3, head,size);

    display(head);
}