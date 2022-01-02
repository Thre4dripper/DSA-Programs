#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};
//function for printing BT Parent->left->right
void display(node *root)
{
    if (root == NULL)
    {
        cout << "Empty!!";
        return;
    }

    cout << root->data << " ";

    if (root->left != NULL)
        display(root->left);

    if (root->right != NULL)
        display(root->right);
}

//function for inserting element in BST
node *Insert(int element, node *root)
{
    node *ptr = new node;
    if (root == NULL)
    {
        ptr->data = element;
        ptr->left = ptr->right = NULL;
        root = ptr;

        return root;
    }
    else
    {
        if (element < root->data)
            root->left = Insert(element, root->left);
        else if (element > root->data)
            root->right = Insert(element, root->right);
        else
            //ignore and return same element
            return root;
    }
}
int main()
{
    system("cls");
    node *root = NULL;
    root = Insert(20, root);
    root = Insert(11, root);
    root = Insert(30, root);
    root = Insert(5, root);
    root = Insert(6, root);
    root = Insert(25, root);
    root = Insert(35, root);
    root = Insert(35, root);
    //it ignores duplicate elements automatically

    //smaller elements on left and larger on right
    //
    //         20
    //       /   \
    //     11    30
    //   /      /  \
    //  5     25   35
    //   \
    //    6

    display(root);
}