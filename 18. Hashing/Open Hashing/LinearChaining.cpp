#include <iostream>
using namespace std;

//size of hash table
#define SIZE 5

struct Node
{
    int data;
    Node *next;
};

//function to print whole hash table
void display(Node *HT[])
{
    Node *p = NULL;
    for (int i = 0; i < SIZE; i++)
    {
        p = HT[i];
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
}

//hash function
int hx(int x)
{
    return x % SIZE;
}

//function for searching element in hashtable
bool Search(int element, Node *HT[])
{
    int index = hx(element);

    Node *p = HT[index];

    while (p != NULL)
    {
        if (p->data == element)
            return true;
        p = p->next;
    }

    return false;
}

//function to insert element in hash table
void Insert(int element, Node *HT[])
{
    if (Search(element, HT) == true)
        return;

    Node *ptr = new Node;
    ptr->data = element;
    ptr->next = NULL;

    int index = hx(element);

    Node *p = HT[index];
    if (p == NULL)
        HT[index] = ptr;
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
    }
}

//function for removing element from hashtable
int Remove(int element, Node *HT[])
{
    if (Search(element, HT) == false)
    {
        cout << "Not Found!!!" << endl;
        return -1;
    }

    int index = hx(element);
    Node *p = HT[index];

    //element present at 'index' at first place
    if (p->data == element)
    {
        Node *ptr = p;
        HT[index] = HT[index]->next;
        delete ptr;
    }
    //element present at 'index' after first place
    else
    {
        while (p != NULL)
        {
            if (p->next->data == element)
            {
                Node *ptr = p->next;
                p->next = p->next->next;
                delete ptr;
            }

            p = p->next;
        }
    }

    return element;
}

int main()
{
    system("cls");
    Node *HashTable[SIZE];

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
    Insert(10, HashTable);
    Insert(7, HashTable);

    cout << Remove(23, HashTable) << endl;
    cout << Search(23, HashTable) << endl;

    display(HashTable);
}