#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

//function for counting nodes
int count(node *root)
{
    if (root == NULL)
        return 0;

    return 1 + count(root->left) + count(root->right);
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

        //         10
    //       /   \
    //     20    30
    //   /  \   /  \
    //  40  50 60  70

    cout << count(root);
}