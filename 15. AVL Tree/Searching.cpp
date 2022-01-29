#include <iostream>
using namespace std;

//AVL TREE IS NOTHING BUT A HEIGHT BALANCED BST, SO SEARCHING IS SAME AS IN BST
struct Node
{
    int data;
    //balance factor
    int bf;
    Node *left;
    Node *right;
};

//function for searching element in BST
int Search(int element, Node *root)
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

    Node *root = NULL;
    Node *first = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *forth = new Node;
    Node *fifth = new Node;

    root = first;
    first->data = 2;
    first->left = second;
    first->right = third;
    first->bf = -1;

    second->data = 1;
    second->left = NULL;
    second->right = NULL;
    second->bf = 0;

    third->data = 4;
    third->left = forth;
    third->right = fifth;
    third->bf = -1;

    forth->data = 3;
    forth->left = NULL;
    forth->right = NULL;
    forth->bf = 0;

    fifth->data = 5;
    fifth->left = NULL;
    fifth->right = NULL;
    fifth->bf = 0;

    //      Sample AVL tree
    //
    //          2
    //        /  \
    //      1     4
    //          /  \
    //         3    5
    //

    cout << Search(3, root);
}