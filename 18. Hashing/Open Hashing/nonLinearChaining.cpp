#include <iostream>
using namespace std;

//size of hash table
#define SIZE 5

//BST node structure
struct node
{
    int data;
    node *left;
    node *right;
};

//function for printing BST left->Parent->right
void displayBST(node *root)
{
    if (root == NULL)
        return;

    if (root->left != NULL)
        displayBST(root->left);

    cout << root->data << " ";

    if (root->right != NULL)
        displayBST(root->right);
}

//function for searching BST left->Parent->right
bool SearchBST(int element, node *root)
{
    if (root == NULL)
        return false;

    if (root->left != NULL)
        return SearchBST(element, root->left);

    if (root->data == element)
        return true;

    if (root->right != NULL)
        return SearchBST(element, root->right);

    return false;
}

//function for inserting element in BST
node *InsertBST(int element, node *root)
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
        root->left = InsertBST(element, root->left);
    else if (element > root->data)
        root->right = InsertBST(element, root->right);

    return root;
}

//function for getting heigth of BST
int HeightBST(node *root)
{
    if (root == NULL)
        return 0;
    int x = HeightBST(root->left) + 1;
    int y = HeightBST(root->right) + 1;

    return x > y ? x : y;
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
node *RemoveBST(int element, node *root)
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
            return NULL;
        }
        else
        {
            node *p = NULL;

            //selection of replacing node will be based on
            //left and right sub tree's height
            if (HeightBST(root->left) > HeightBST(root->right))
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

//function to print whole hash table
void display(node *HT[])
{
    node *p = NULL;
    for (int i = 0; i < SIZE; i++)
    {
        p = HT[i];
        displayBST(p);
    }
}

//hash function
int hx(int x)
{
    return x % SIZE;
}

//function for searching element in hashtable
bool Search(int element, node *HT[])
{
    int index = hx(element);

    return SearchBST(element, HT[index]);
}

//function to insert element in hash table
void Insert(int element, node *HT[])
{
    if (Search(element, HT) == true)
        return;

    int index = hx(element);

    HT[index] = InsertBST(element, HT[index]);
}

//function for removing element from hashtable
int Remove(int element, node *HT[])
{
    if (Search(element, HT) == false)
    {
        cout << "Not Found!!!" << endl;
        return -1;
    }

    int index = hx(element);

    HT[index] = RemoveBST(element, HT[index]);

    return element;
}

int main()
{
    system("cls");
    node *HashTable[SIZE];

    for (int i = 0; i < SIZE; i++)
        HashTable[i] = NULL;

    Insert(10, HashTable);
    Insert(15, HashTable);
    Insert(24, HashTable);
    Insert(23, HashTable);
    Insert(18, HashTable);
    Insert(36, HashTable);
    Insert(2, HashTable);
    Insert(3, HashTable);
    Insert(42, HashTable);
    Insert(1, HashTable);
    Insert(7, HashTable);

    cout << Remove(7, HashTable) << endl;
    cout << Search(7, HashTable) << endl;

    display(HashTable);
}