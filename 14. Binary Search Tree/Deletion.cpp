#include <iostream>
#include <queue>

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

//function for initial filling of BST
node *Insert(int element, node *root)
{
    node *ptr = NULL;
    if (root == NULL)
    {
        ptr = new node;
        ptr->data = element;
        ptr->left = ptr->right = NULL;
        return ptr;
    }

    if (element < root->data)
        root->left = Insert(element, root->left);
    else if (element > root->data)
        root->right = Insert(element, root->right);

    return root;
}

//fucntion to find inorder succ
node *inorderSuccessor(node *root)
{
    node *ptr = root;
    while (ptr->right != NULL)
        ptr = ptr->right;

    return ptr;
}

node *Remove(int element, node *root)
{
    //element not found
    if (root == NULL)
        return NULL;

    if (element == root->data)
    {
        //leaf node
        if (root->left == NULL && root->right == NULL)
            return NULL;

        //only left child
        else if (root->left != NULL && root->right == NULL)
        {
            node *p = root->left;
            delete root;
            return p;
        }

        //only right child
        else if (root->left == NULL && root->right != NULL)
        {
            node *p = root->right;
            delete root;
            return p;
        }
        //both children exist
        else
        {
            node *p = inorderSuccessor(root->left);
            root->data = p->data;
            root->left = Remove(p->data, root->left);
        }
    }
    //element might be in left BST
    else if (element < root->data)
        root->left = Remove(element, root->left);
    //element might be in right BST
    else
        root->right = Remove(element, root->right);
}

int main()
{
    system("cls");
    node *root = NULL;

    int arr[] = {50, 55, 10, 40, 20, 30};
    //         50
    //       /   \
    //     10    55
    //       \  
    //        40
    //       /
    //     20
    //       \
    //        30

    //initial filling of BST
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        root = Insert(arr[i], root);

    cout << "Before Deletion: ";
    display(root);

    root = Remove(50, root);

    cout << "\nAfter Deletion: ";
    display(root);
}