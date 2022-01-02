#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

//function for searching element in BST
int Search(int element, node *root)
{
    //element not fount
    if (root == NULL)
        return 0;

    //element found
    if (element == root->data)
        return 1;
    //element might be in left BST
    else if (element < root->data)
        return Search(element, root->left);
    //element might be in right BST
    else if (element > root->data)
        return Search(element, root->right);
}

int main()
{
    system("cls");
    node *root = NULL;
    node *first = new node;
    node *second = new node;
    node *third = new node;
    node *forth = new node;
    node *fifth = new node;
    node *sixth = new node;
    node *seventh = new node;

    root = first;

    first->data = 40;
    first->left = second;
    first->right = third;

    second->data = 20;
    second->left = forth;
    second->right = fifth;

    third->data = 50;
    third->left = sixth;
    third->right = seventh;

    forth->data = 10;
    forth->left = NULL;
    forth->right = NULL;

    fifth->data = 30;
    fifth->left = NULL;
    fifth->right = NULL;

    sixth->data = 60;
    sixth->left = NULL;
    sixth->right = NULL;

    seventh->data = 70;
    seventh->left = NULL;
    seventh->right = NULL;

    //         40
    //       /   \
    //     20    50
    //   /  \   /  \
    //  10  30 60  70

    cout << Search(30, root);
}