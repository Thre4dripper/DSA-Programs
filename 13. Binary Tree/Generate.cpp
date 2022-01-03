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

//function for generating whole binary tree
void insert(node **root)
{
    //initial work
    node *rootNode = new node;
    queue<node *> q;

    cout << "Enter root Element: ";
    cin >> rootNode->data;

    if (rootNode->data == -1)
    {
        *root = NULL;
        return;
    }

    rootNode->left = NULL;
    rootNode->right = NULL;

    q.push(rootNode);
    *root = rootNode;

    //infinite loop until queue becomes empty
    while (!q.empty())
    {
        node *p;
        p = q.front();
        q.pop();

        //for entering left child
        node *lchild = new node;
        cout << "Enter Left child of " << p->data << ": ";
        cin >> lchild->data;

        lchild->left = lchild->right = NULL;
        if (lchild->data != -1)
            q.push(lchild);
        else
            lchild = NULL;

        p->left = lchild;

        //for entering right child
        node *rchild = new node;
        cout << "Enter right child of " << p->data << ": ";
        cin >> rchild->data;

        rchild->left = rchild->right = NULL;
        if (rchild->data != -1)
            q.push(rchild);
        else
            rchild = NULL;

        p->right = rchild;
    }
}

int main()
{
    system("cls");

    //there is no general rule in binary tree to insert single node
    //so generally whole BT will be generated at once

    node *root = NULL;

    insert(&root);

    cout << endl
         << "Binary Tree: ";
    display(root);
}