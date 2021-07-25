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

//definition for replacing of element from start of linked list directly from its address
int replaceFromStart(int element,node **head){
    int initelement=NULL;

    if(*head!=NULL){

        initelement = (*head)->data;
         (*head)->data = element;

    }
    else
        cout << "Linked list Underflow"<<endl;

    return initelement;
}

//definition for replacing of element from end of linked list directly from its address
int replaceFromEnd(int element,node **head){
    int initelement=NULL;

    if(*head!=NULL){
        node *ptr = new node;
        ptr = *head;

        //only last node has next as NULL
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
            

        initelement = ptr->data;
        ptr->data = element;
    }
    else
        cout << "Linked list Underflow"<<endl;

    return initelement;
}

//definition for replacing of element from any index of linked list directly from its address
int replaceFromIndex(int element,int index,node ** head,int size){
    int initelement=NULL;

    if(*head!=NULL){
        node *ptr = new node;

        //scenario will be diff for '0' index (very begenning)
        if(index==0){
            initelement = (*head)->data;
            (*head)->data = element;
        }
        //for indexes smaller than linked list size  
        else if(index<size){
            ptr = (*head);

            

            for (int i = 0; i < index && ptr->next != NULL; i++)
            {
                ptr = ptr->next;
            }

            //simply replacing data of desired node
            initelement = ptr->data;
            ptr->data = element;
        }
        else
            cout << "Index greater than Linked list size"<<endl;

    }
    else
        cout << "Linked list Underflow"<<endl;

    return initelement;
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

    size=display(head);

    cout<<endl<<replaceFromIndex(41,5,&head,size);

    display(head);
}