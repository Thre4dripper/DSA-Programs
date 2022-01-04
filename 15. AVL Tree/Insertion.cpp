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

//              z                                      y
//             / \                                   /   \
//            y   T4      Right-Right Rotate (z)          x     z
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

//          z                                y
//        /  \                             /  \ 
//       T1   y     Left-Left Rotate(z)       z     x
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

//function for inserting element in AVL tree
node *Insert(int element, node *root)
{
    node *ptr = NULL;
    if (root == NULL)
    {
        ptr = new node;
        ptr->data = element;
        ptr->left = ptr->right = NULL;
        ptr->bf = 0;
        return ptr;
    }

    if (element < root->data)
        root->left = Insert(element, root->left);
    else if (element > root->data)
        root->right = Insert(element, root->right);

    //calculating balance factor of every node at returning time
    root->bf = BalanceFactor(root);

    //left-left imbalance
    if (root->bf == 2 && root->left->bf == 1)
        return RRrotation(root);

    //left-right imbalance
    else if (root->bf == 2 && root->left->bf == -1)
        return LRrotation(root);

    //right-left imbalance
    else if (root->bf == -2 && root->right->bf == 1)
        return RLrotation(root);

    //right-right imbalance
    else if (root->bf == -2 && root->right->bf == -1)
        return LLrotation(root);

    //these rotations were done on recursions's return time
    return root;
}

int main()
{
    system("cls");
    node *root = NULL;

    //these are only few emenents to test AVL tree but
    //AVL tree is invented in such a way that node of the two cases of rotation will contradict
    //even on very large no of elements
    root = Insert(20, root);
    root = Insert(4, root);
    root = Insert(26, root);
    root = Insert(3, root);
    root = Insert(9, root);
    root = Insert(15, root);

    display(root);
    cout << endl
         << "Root: " << root->data;
}