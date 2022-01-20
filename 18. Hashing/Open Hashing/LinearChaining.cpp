#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

//function to print whole hash table
void display(node *HashTable[], int size)
{
    node *p = NULL;
    for (int i = 0; i < size; i++)
    {
        p = HashTable[i];
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
}

//hash function
int hx(int x, int size)
{
    return x % size;
}

//function for searching element in hashtable
bool Search(int element, node *HashTable[], int size)
{
    int index = hx(element, size);

    node *p = HashTable[index];

    while (p != NULL)
    {
        if (p->data == element)
            return true;
        p = p->next;
    }

    return false;
}

//function to insert element in hash table
void Insert(int element, node *HashTable[], int size)
{
    if (Search(element, HashTable, size) == true)
        return;

    node *ptr = new node;
    ptr->data = element;
    ptr->next = NULL;

    int index = hx(element, size);

    node *p = HashTable[index];
    if (p == NULL)
        HashTable[index] = ptr;
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
int Remove(int element, node *HashTable[], int size)
{
    if (Search(element, HashTable, size) == false)
    {
        cout << "Not Found!!!" << endl;
        return -1;
    }

    int index = hx(element, size);
    node *p = HashTable[index];

    //element present at 'index' at first place
    if (p->data == element)
    {
        node *ptr = p;
        HashTable[index] = HashTable[index]->next;
        delete ptr;
    }
    //element present at 'index' after first place
    else
    {
        while (p != NULL)
        {
            if (p->next->data == element)
            {
                node *ptr = p->next;
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
    int size = 5;
    node *HashTable[size];

    for (int i = 0; i < size; i++)
        HashTable[i] = NULL;

    Insert(10, HashTable, size);
    Insert(15, HashTable, size);
    Insert(24, HashTable, size);
    Insert(23, HashTable, size);
    Insert(18, HashTable, size);
    Insert(36, HashTable, size);
    Insert(2, HashTable, size);
    Insert(3, HashTable, size);
    Insert(42, HashTable, size);
    Insert(10, HashTable, size);
    Insert(7, HashTable, size);

    cout << Remove(23, HashTable, size) << endl;
    cout << Search(23, HashTable, size) << endl;

    display(HashTable, size);
}