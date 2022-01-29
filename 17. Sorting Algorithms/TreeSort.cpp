#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

//function for inserting element in BST
Node *InsertBST(int element, Node *root)
{
    Node *ptr = NULL;
    if (root == NULL)
    {
        ptr = new Node;
        ptr->data = element;
        ptr->left = ptr->right = NULL;

        return ptr;
    }

    // '<=' for allowance for duplicate keys for sorting purpose only
    // otherwise BST should not have duplicate keys
    if (element <= root->data)
        root->left = InsertBST(element, root->left);
    else if (element > root->data)
        root->right = InsertBST(element, root->right);

    return root;
}

//function for extracting keys from BST in sorted way using inorder traversal
void SortByInorder(int arr[], Node *root)
{
    //static variable for singleton pattern
    static int index = 0;

    if (root != NULL)
    {
        if (root->left != NULL)
            SortByInorder(arr, root->left);

        arr[index++] = root->data;

        if (root->right != NULL)
            SortByInorder(arr, root->right);
    }
}

//function for sorting array using Tree Sort (Binary Search Tree)
int *TreeSort(int arr[], int n)
{
    Node *BST = NULL;

    for (int i = 0; i < n; i++)
        BST = InsertBST(arr[i], BST);

    SortByInorder(arr, BST);

    return arr;
}

int main()
{
    system("cls");
    int arr[] = {2, 5, 41, 6, 8, 25, 41, 5, 63, 1, 4, 6, 2, 1, 1, 52, 74, 96, 20, 54, 4, 6, 52, 45, 89, 63, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *ptr;

    ptr = TreeSort(arr, size);

    for (int i = 0; i < size; i++)
        cout << ptr[i] << " ";
}