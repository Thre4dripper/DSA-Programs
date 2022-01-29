#include<iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
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

//definition for insert element at start of linked list
Node * insertAtStart(int element, Node *head){

    Node *ptr = new Node;
    ptr->data = element;
    ptr->next = head;

    return ptr;
}

//definition for insert element at end of linked list
Node * insertAtEnd(int element, Node * head){
    Node *ptr = new Node;
    ptr->data = element;
    ptr->next = NULL;

    Node *p = head;

    //only last node has next as NULL
    while(p->next!=NULL)
        p = p->next;

    p->next = ptr;

    return head;
}

//definition for insert element at any index of linked list
Node * insertAtIndex(int element,int index,Node * head,int size){
    Node *ptr = new Node;
    ptr->data = element;

    //scenario will be diff for '0' index (very begenning)
    if(index==0){
        ptr->next = head;
        head = ptr;
    }
    //for indexes smaller than linked list size  
     else if(index<=size){
        Node *p=head;

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

    Node *head=new Node;
    Node *second = new Node;
    Node *third = new Node;

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