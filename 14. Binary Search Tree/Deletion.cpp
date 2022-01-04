#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

//function for printing BT left->Parent->right
void display(node *root)
{
    if (root == NULL)
    {
        cout << "Empty!!";
        return;
    }

    if (root->left != NULL)
        display(root->left);

    cout << root->data << " ";

    if (root->right != NULL)
        display(root->right);
}

//function for getting heigth of binary tree
int Height(node *root)
{
    if (root == NULL)
        return 0;
    int x = Height(root->left) + 1;
    int y = Height(root->right) + 1;

    return x > y ? x : y;
}

//function for getting balance factor of node
int BalanceFactor(node *ptr)
{
    int hL, hR;
    hL = Height(ptr->left);
    hR = Height(ptr->right);

    return hL - hR;
}

//fucntion to find inorder predec
node *inorderPredecessor(node *root)
{
    node *ptr = root;
    while (ptr != NULL && ptr->right != NULL)
        ptr = ptr->right;

    return ptr;
}

//fucntion to find inorder succ
node *inorderSuccessor(node *root)
{
    node *ptr = root;
    while (ptr != NULL && ptr->left != NULL)
        ptr = ptr->left;

    return ptr;
}

//function for deleting element from BST
node *Remove(int element, node *root)
{
    //element not found
    if (root == NULL)
        return NULL;

    if (element < root->data)
        root->left = Remove(element, root->left);
    else if (element > root->data)
        root->right = Remove(element, root->right);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else
        {
            node *p = NULL;

            //selection of replacing node will be based on
            //left and right sub tree's height
            if (Height(root->left) > Height(root->right))
            {
                p = inorderPredecessor(root->left);
                root->data = p->data;
                root->left = Remove(p->data, root->left);
            }
            else
            {
                p = inorderSuccessor(root->right);
                root->data = p->data;
                root->right = Remove(p->data, root->right);
            }
        }
    }

    return root;
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

    root = first;
    first->data = 2;
    first->left = second;
    first->right = third;

    second->data = 1;
    second->left = NULL;
    second->right = NULL;

    third->data = 4;
    third->left = forth;
    third->right = fifth;

    forth->data = 3;
    forth->left = NULL;
    forth->right = NULL;

    fifth->data = 5;
    fifth->left = NULL;
    fifth->right = NULL;

    //      Sample BST
    //
    //          2
    //        /  \
    //      1     4
    //          /  \
    //         3    5
    //

    cout << "Before Deletion: ";
    display(root);

    root = Remove(50, root);

    cout << "\nAfter Deletion: ";
    display(root);

    cout << "\nRoot: " << root->data;
}