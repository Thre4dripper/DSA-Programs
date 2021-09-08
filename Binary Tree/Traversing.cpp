#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

//function for printing BT Parent->left->right
void PreOrderTraverse(node *head){
    cout << head->data<<" ";

    if(head->left!=NULL)
        PreOrderTraverse(head->left);

    if(head->right!=NULL)
        PreOrderTraverse(head->right);
    
}

//function for printing BT left->Parent->right
void InOrderTraverse(node *head){
    

    if(head->left!=NULL)
        InOrderTraverse(head->left);

        cout << head->data<<" ";

    if(head->right!=NULL)
        InOrderTraverse(head->right);
    
}

//function for printing BT right->left->Parent
void PostOrderTraverse(node *head){
    

    if(head->right!=NULL)
        PostOrderTraverse(head->right);

    if(head->left!=NULL)
        PostOrderTraverse(head->left);

        cout << head->data<<" ";
 
}

int main(){
    system("cls");
    node *head=NULL;
    node *first = new node;
    node *second = new node;
    node *third = new node;
    node *forth = new node;
    node *fifth = new node;
    node *sixth = new node;
    node *seventh = new node;

    head = first;

    first->data = 10;
    first->left = second;
    first->right = third;

    second->data = 20;
    second->left = forth;
    second->right = fifth;

    third->data = 30;
    third->left = sixth;
    third->right = seventh;

    forth->data = 40;
    forth->left = NULL;
    forth->right = NULL;

    fifth->data = 50;
    fifth->left = NULL;
    fifth->right = NULL;

    sixth->data = 60;
    sixth->left = NULL;
    sixth->right = NULL;

    seventh->data = 70;
    seventh->left = NULL;
    seventh->right = NULL;

    PostOrderTraverse(head);
}