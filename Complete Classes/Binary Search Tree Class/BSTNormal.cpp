#include <iostream>
#include <queue>
using namespace std;

//binary search tree class implementation
class BST
{
private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;
    };
    Node *root;
    int size;

    //function for inserting element in BST
    Node *InsertBST(int element, Node *root)
    {
        Node *ptr = NULL;
        if (root == NULL)
        {
            ptr = new Node;
            ptr->data = element;
            ptr->left = ptr->right = NULL;

            size++;
            return ptr;
        }

        if (element < root->data)
            root->left = InsertBST(element, root->left);
        else if (element > root->data)
            root->right = InsertBST(element, root->right);

        return root;
    }

    //function for getting heigth of binary tree
    int Height(Node *root)
    {
        if (root == NULL)
            return 0;
        int x = Height(root->left) + 1;
        int y = Height(root->right) + 1;

        return x > y ? x : y;
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

    //function for deleting element from BST
    Node *RemoveBST(int element, Node *root)
    {
        //element not found
        if (root == NULL)
            return NULL;

        if (element < root->data)
            root->left = RemoveBST(element, root->left);
        else if (element > root->data)
            root->right = RemoveBST(element, root->right);
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
                if (Height(root->left) > Height(root->right))
                {
                    p = inorderPredecessor(root->left);
                    root->data = p->data;
                    root->left = RemoveBST(p->data, root->left);
                }
                else
                {
                    p = inorderSuccessor(root->right);
                    root->data = p->data;
                    root->right = RemoveBST(p->data, root->right);
                }
            }
        }

        return root;
    }

    //function for searching element in BST
    int SearchBST(int element, Node *root)
    {
        //element not fount
        if (root == NULL)
            return 0;

        //element found
        if (element == root->data)
            return 1;
        //element might be in left BST
        else if (element < root->data)
            return SearchBST(element, root->left);
        //element might be in right BST
        else if (element > root->data)
            return SearchBST(element, root->right);
    }

    //function for deleting all the nodes from BST
    void ClearBST(Node *root)
    {
        if (root != NULL)
        {
            if (root->left != NULL)
                ClearBST(root->left);

            if (root->right != NULL)
                ClearBST(root->right);

            delete root;
        }
    }

    //function for printing BT left->Parent->right
    void displayBSTInorder(Node *root)
    {
        if (root != NULL)
        {
            if (root->left != NULL)
                displayBSTInorder(root->left);

            cout << root->data << " ";

            if (root->right != NULL)
                displayBSTInorder(root->right);
        }
    }

    //function for printing BT left->Parent->right
    void displayBSTPreorder(Node *root)
    {
        if (root != NULL)
        {
            cout << root->data << " ";

            if (root->left != NULL)
                displayBSTInorder(root->left);

            if (root->right != NULL)
                displayBSTInorder(root->right);
        }
    }

    //function for printing BT left->Parent->right
    void displayBSTPostorder(Node *root)
    {
        if (root != NULL)
        {
            if (root->left != NULL)
                displayBSTInorder(root->left);

            if (root->right != NULL)
                displayBSTInorder(root->right);

            cout << root->data << " ";
        }
    }

    //function for printing BST level by level
    void displayBSTLevelorder(Node *root)
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
    BST()
    {
        root = NULL;
        size = 0;
    }

    //function for inserting element in BST
    BST &Insert(int element)
    {
        root = InsertBST(element, root);
        return *this;
    }

    //function for removing element from BST
    BST &Remove(int element)
    {
        root = RemoveBST(element, root);
        return *this;
    }

    //function checking BST is empty or not
    bool isEmpty()
    {
        if (root == NULL)
            return true;
        return false;
    }

    //function getting root element in BST
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

    //function for getting height of BST
    int Height()
    {
        return Height(root) - 1;
    }

    //function for getting levels of BST
    int Levels()
    {
        return Height(root);
    }

    //function for searching element in BST
    int Search(int element)
    {
        return SearchBST(element, root);
    }

    //function for clearing elements from BST
    BST &Clear()
    {
        ClearBST(root);
        root = NULL;
        return *this;
    }

    //function for displaying elements using InOrder Traversal
    BST &displayInorder()
    {
        displayBSTInorder(root);
        return *this;
    }

    //function for displaying elements using PreOrder Traversal
    BST &displayPreorder()
    {
        displayBSTPreorder(root);
        return *this;
    }

    //function for displaying elements using PostOrder Traversal
    BST &displayPostorder()
    {
        displayBSTPostorder(root);
        return *this;
    }

    //function for displaying elements using LevelOrder Traversal
    BST &displayLevelorder()
    {
        displayBSTLevelorder(root);
        return *this;
    }

    //function for getting no of nodes in BST
    int Size()
    {
        return size;
    }
};

int main()
{
    system("cls");

    //binary search tree class objects declaration
    BST bst;

    bst.Insert(2).Insert(1).Insert(4).Insert(3).Insert(5);
    cout << bst.Size() << endl;

    bst.Remove(2).Remove(3);

    bst.displayInorder();
}
