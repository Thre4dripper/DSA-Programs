#include <iostream>
#include <queue>
using namespace std;

//AVL tree class implementation
class AVLTree
{
private:
    struct Node
    {
        int data;
        //balance factor
        int bf;
        Node *left;
        Node *right;
    };
    Node *root;
    int size;

    //function for getting heigth of binary tree
    int HeightAVL(Node *root)
    {
        if (root == NULL)
            return 0;
        int x = HeightAVL(root->left) + 1;
        int y = HeightAVL(root->right) + 1;

        return x > y ? x : y;
    }

    //function for getting balance factor of node
    int BalanceFactorAVL(Node *ptr)
    {
        int hL, hR;
        hL = HeightAVL(ptr->left);
        hR = HeightAVL(ptr->right);

        return hL - hR;
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
    Node *RRrotation(Node *ptr)
    {
        Node *p = ptr->left;

        ptr->left = p->right;
        p->right = ptr;

        ptr->bf = BalanceFactorAVL(ptr);
        p->bf = BalanceFactorAVL(p);

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
    Node *LLrotation(Node *ptr)
    {
        Node *p = ptr->right;

        ptr->right = p->left;
        p->left = ptr;

        ptr->bf = BalanceFactorAVL(ptr);
        p->bf = BalanceFactorAVL(p);

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
    Node *LRrotation(Node *ptr)
    {
        Node *p = ptr->left;
        Node *p1 = p->right;

        ptr->left = p1->right;
        p->right = p1->left;

        p1->left = p;
        p1->right = ptr;

        ptr->bf = BalanceFactorAVL(ptr);
        p->bf = BalanceFactorAVL(p);
        p1->bf = BalanceFactorAVL(p1);

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
    //      T2   T3                          T3  T4
    Node *RLrotation(Node *ptr)
    {
        Node *p = ptr->right;
        Node *p1 = p->left;

        ptr->right = p1->left;
        p->left = p1->right;

        p1->right = p;
        p1->left = ptr;

        ptr->bf = BalanceFactorAVL(ptr);
        p->bf = BalanceFactorAVL(p);
        p1->bf = BalanceFactorAVL(p1);

        return p1;
    }

    //function for inserting element in AVL tree
    Node *InsertAVL(int element, Node *root)
    {
        Node *ptr = NULL;
        if (root == NULL)
        {
            ptr = new Node;
            ptr->data = element;
            ptr->left = ptr->right = NULL;
            ptr->bf = 0;

            size++;
            return ptr;
        }

        if (element < root->data)
            root->left = InsertAVL(element, root->left);
        else if (element > root->data)
            root->right = InsertAVL(element, root->right);

        //calculating balance factor of every node at returning time
        root->bf = BalanceFactorAVL(root);

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

    //fucntion to find inorder predec
    Node *inorderPredecessor(Node *root)
    {
        Node *ptr = root;
        while (ptr != NULL && ptr->right != NULL)
            ptr = ptr->right;

        return ptr;
    }

    //fucntion to find inorder succ
    Node *inorderSuccessor(Node *root)
    {
        Node *ptr = root;
        while (ptr != NULL && ptr->left != NULL)
            ptr = ptr->left;

        return ptr;
    }

    //function for deleting element from AVL tree
    Node *RemoveAVL(int element, Node *root)
    {
        //element not found
        if (root == NULL)
            return NULL;

        if (element < root->data)
            root->left = RemoveAVL(element, root->left);
        else if (element > root->data)
            root->right = RemoveAVL(element, root->right);
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                size--;
                return NULL;
            }
            else
            {
                Node *p = NULL;

                //selection of replacing node will be based on
                //left and right sub tree's height
                if (HeightAVL(root->left) > HeightAVL(root->right))
                {
                    p = inorderPredecessor(root->left);
                    root->data = p->data;
                    root->left = RemoveAVL(p->data, root->left);
                }
                else
                {
                    p = inorderSuccessor(root->right);
                    root->data = p->data;
                    root->right = RemoveAVL(p->data, root->right);
                }
            }
        }

        //here is the diff begin from normal BST

        //calculating balance factor of every node at returning time
        root->bf = BalanceFactorAVL(root);

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

    //function for searching element in AVL tree
    int SearchAVL(int element, Node *root)
    {
        //element not fount
        if (root == NULL)
            return 0;

        //element found
        if (element == root->data)
            return 1;
        //element might be in left AVL tree
        else if (element < root->data)
            return SearchAVL(element, root->left);
        //element might be in right AVl tree
        else if (element > root->data)
            return SearchAVL(element, root->right);
    }

    //function for deleting all the nodes from AVL tree
    void ClearAVL(Node *root)
    {
        if (root != NULL)
        {
            if (root->left != NULL)
                ClearAVL(root->left);

            if (root->right != NULL)
                ClearAVL(root->right);

            delete root;
        }
    }

    //function for printing AVL tree left->Parent->right
    void displayAVLInorder(Node *root)
    {
        if (root != NULL)
        {
            if (root->left != NULL)
                displayAVLInorder(root->left);

            cout << root->data << " ";

            if (root->right != NULL)
                displayAVLInorder(root->right);
        }
    }

    //function for printing AVL tree left->Parent->right
    void displayAVLPreorder(Node *root)
    {
        if (root != NULL)
        {
            cout << root->data << " ";

            if (root->left != NULL)
                displayAVLPreorder(root->left);

            if (root->right != NULL)
                displayAVLPreorder(root->right);
        }
    }

    //function for printing AVL tree left->Parent->right
    void displayAVLPostorder(Node *root)
    {
        if (root != NULL)
        {
            if (root->left != NULL)
                displayAVLPostorder(root->left);

            if (root->right != NULL)
                displayAVLPostorder(root->right);

            cout << root->data << " ";
        }
    }

    //function for printing AVL tree level by level
    void displayAVLLevelorder(Node *root)
    {
        if (root == NULL)
            return;

        //initial work
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *p = q.front();
            q.pop();

            cout << p->data << " ";

            if (p->left != NULL)
                q.push(p->left);

            if (p->right != NULL)
                q.push(p->right);
        }
    }

public:
    //constructor for initializing root and size
    AVLTree()
    {
        root = NULL;
        size = 0;
    }

    //function for inserting element in AVL tree
    AVLTree &Insert(int element)
    {
        root = InsertAVL(element, root);
        return *this;
    }

    //function for removing element from AVL tree
    AVLTree &Remove(int element)
    {
        root = RemoveAVL(element, root);
        return *this;
    }

    //function checking AVL tree is empty or not
    bool isEmpty()
    {
        if (root == NULL)
            return true;
        return false;
    }

    //function getting root element in AVL tree
    int Root()
    {
        if (isEmpty() == false)
            return root->data;
        return NULL;
    }

    //function checking element is root or not
    bool isRoot(int element)
    {
        if (root != NULL && element == root->data)
            return true;
        return false;
    }

    //function for getting height of AVL tree
    int Height()
    {
        return HeightAVL(root) - 1;
    }

    //function for getting levels of AVL tree
    int Levels()
    {
        return HeightAVL(root);
    }

    //function for searching element in AVL tree
    int Search(int element)
    {
        return SearchAVL(element, root);
    }

    //function for clearing elements from AVL tree
    AVLTree &Clear()
    {
        ClearAVL(root);
        root = NULL;
        return *this;
    }

    //function for displaying elements using InOrder Traversal
    AVLTree &displayInorder()
    {
        displayAVLInorder(root);
        return *this;
    }

    //function for displaying elements using PreOrder Traversal
    AVLTree &displayPreorder()
    {
        displayAVLPreorder(root);
        return *this;
    }

    //function for displaying elements using PostOrder Traversal
    AVLTree &displayPostorder()
    {
        displayAVLPostorder(root);
        return *this;
    }

    //function for displaying elements using LevelOrder Traversal
    AVLTree &displayLevelorder()
    {
        displayAVLLevelorder(root);
        return *this;
    }

    //function for getting no of nodes in AVL tree
    int Size()
    {
        return size;
    }
};

int main()
{
    system("cls");

    //AVL tree class object declaration
    AVLTree avlt;

    avlt.Insert(2).Insert(1).Insert(4).Insert(3).Insert(5);

    cout << avlt.Size() << endl;

    avlt.Remove(2).Remove(3);

    avlt.displayInorder();
}
