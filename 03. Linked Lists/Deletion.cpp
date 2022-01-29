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

//definition for deletion of element from start of linked list directly from its address
int deleteFromStart(Node **head){
    int element=NULL;

    if(*head!=NULL){
        Node *ptr = new Node;
        ptr = *head;

        element = (*head)->data;
        (*head) = (*head)->next;

        delete ptr;

    }
    else
        cout << "Linked list Underflow"<<endl;

    return element;
}

//definition for deletion of element From end of linked list directly from its address
int deleteFromEnd(Node **head){
    int element=NULL;

    if(*head!=NULL){
        Node *ptr = new Node;
        ptr = *head;

        Node *p = new Node;

        //only last node has next as NULL
        //and  p lags ptr by one node , thats what we want
        while(ptr->next!=NULL){
            p = ptr;
            ptr = ptr->next;
        }
            

        element = ptr->data;
        p->next = NULL;
        delete ptr;
    }
    else
        cout << "Linked list Underflow"<<endl;

    return element;
}

//definition for delete element from any index of linked list directly from its address
int deleteFromIndex(int index,Node ** head,int *size){
    int element=NULL;

    if(*head!=NULL){
        Node *ptr = new Node;

        //scenario will be diff for '0' index (very begenning)
        if(index==0){
            ptr= *head;

            element = ptr->data;
            (*head) = (*head)->next;
        }
        //for indexes smaller than linked list size  
        else if(index<(*size)){
            ptr = (*head);

            Node *p = new Node;

            for (int i = 0; i < index && ptr->next != NULL; i++)
            {
                p = ptr;
                ptr = ptr->next;
            }

            //simply skipping indexed node and deleting it later
            p->next = ptr->next;

            element = ptr->data;
        }
        else
            cout << "Index greater than Linked list size"<<endl;
        delete ptr;
        (*size)--;
    }
    else
        cout << "Linked list Underflow"<<endl;

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

    cout<<endl<<deleteFromIndex(3,&head,&size);
   
    cout<<endl<<deleteFromIndex(3,&head,&size);
   
    cout<<endl<<deleteFromIndex(3,&head,&size);
    
    cout<<endl<<deleteFromIndex(3,&head,&size);
  


    display(head);
}