#include <iostream>
using namespace std;

struct node
{
    int data;
    //balance factor
    int bf;
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

    cout << root->data << "  Bfactor: " << root->bf << endl;

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

//  Comments are copied from GFG
//
//              z                                      y
//             / \                                   /   \
//            y   T4      Right-Right Rotate (z)    x     z
//           / \          - - - - - - - - ->      /  \   /  \ 
//          x   T3                               T1  T2 T3  T4
//         / \
//       T1   T2
node *RRrotation(node *ptr)
{
    node *p = ptr->left;

    ptr->left = p->right;
    p->right = ptr;

    ptr->bf = BalanceFactor(ptr);
    p->bf = BalanceFactor(p);

    return p;
}

//  Comments are copied from GFG
//
//          z                                y
//        /  \                             /  \ 
//       T1   y     Left-Left Rotate(z)  z     x
//           /  \   - - - - - - - ->    / \   / \
//          T2   x                     T1 T2 T3  T4
//              / \
//            T3  T4
node *LLrotation(node *ptr)
{
    node *p = ptr->right;

    ptr->right = p->left;
    p->left = ptr;

    ptr->bf = BalanceFactor(ptr);
    p->bf = BalanceFactor(p);

    return p;
}

//  Comments are copied from GFG
//
//           z                               z                           x
//          / \                            /   \                       /  \ 
//         y   T4  Left Rotate (y)        x    T4  Right Rotate(z)   y      z
//        / \      - - - - - - - - ->    /  \      - - - - - - - -> / \    / \
//      T1   x                          y    T3                   T1  T2 T3  T4
//          / \                        / \
//        T2   T3                    T1   T2
node *LRrotation(node *ptr)
{
    node *p = ptr->left;
    node *p1 = p->right;

    ptr->left = p1->right;
    p->right = p1->left;

    p1->left = p;
    p1->right = ptr;

    ptr->bf = BalanceFactor(ptr);
    p->bf = BalanceFactor(p);
    p1->bf = BalanceFactor(p1);

    return p1;
}

//  Comments are copied from GFG
//
//         z                            z                             x
//        / \                          / \                          /  \ 
//      T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
//          / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
//         x   T4                      T2   y                  T1  T2  T3  T4
//        / \                              / \
//      T2   T3                           T3  T4
node *RLrotation(node *ptr)
{
    node *p = ptr->right;
    node *p1 = p->left;

    ptr->right = p1->left;
    p->left = p1->right;

    p1->right = p;
    p1->left = ptr;

    ptr->bf = BalanceFactor(ptr);
    p->bf = BalanceFactor(p);
    p1->bf = BalanceFactor(p1);

    return p1;
}

//function for deleting element from AVL tree
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

    //here is the diff begin from normal BST

    //calculating balance factor of every node at returning time
    root->bf = BalanceFactor(root);

    //L 1 imbalance
    if (root->bf == 2 && root->left->bf == 1)
        return RRrotation(root);

    //L 0 imbalance
    else if (root->bf == -2 && root->right->bf == 0)
        return LLrotation(root);

    //L -1 imbalance
    else if (root->bf == 2 && root->left->bf == -1)
        return LRrotation(root);

    //R 1 imbalance
    else if (root->bf == -2 && root->right->bf == 1)
        return RLrotation(root);

    //R 0 imbalance
    else if (root->bf == 2 && root->left->bf == 0)
        return RRrotation(root);

    //R -1 imbalance
    else if (root->bf == -2 && root->right->bf == -1)
        return LLrotation(root);

    //these rotations were done on recursions's return time
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

    cout << "Before Deletion: \n";
    display(root);

    root = Remove(1, root);

    cout << "\nAfter Deletion: \n";
    display(root);

    cout << "\nRoot: " << root->data;
}