#include <iostream>
using namespace std;

#define SIZE 10

//function for display whole hash table
void display(int HT[])
{
    for (int i = 0; i < SIZE; i++)
    {
        if (HT[i] != 0)
            cout << HT[i] << " ";
    }
}

//first hash function
int hx1(int x)
{
    return x % SIZE;
}

//second hash function
int hx2(int x)
{
    return (SIZE - 3) - x % (SIZE - 3);
}

//double hash function
int hx(int HT[], int x)
{
    int i = 0;
    //breaking condition in case non of the indices left
    while (i * hx2(x) < SIZE * hx2(x) && HT[(hx1(x) + i * hx2(x)) % SIZE] != 0)
        i++;

    //whole loop completed
    if (i * hx2(x) == SIZE * hx2(x))
        return -1;

    return (hx1(x) + i * hx2(x)) % SIZE;
}

//function for searching element in hashtable
bool Search(int element, int HT[])
{
    int i = 0;
    //breaking condition in case non of the indices left
    while (i * hx2(element) < SIZE * hx2(element) && HT[(hx1(element) + i * hx2(element)) % SIZE] != element)
        i++;

    //whole loop completed
    if (i * hx2(element) == SIZE * hx2(element))
        return false;

    return true;
}

//function to insert element in hash table
void Insert(int element, int HT[])
{

    if (Search(element, HT) == true)
        return;

    int index = hx(HT, element);

    if (index == -1)
    {
        cout << "HashTable Overflow!!!" << endl;
        return;
    }

    HT[index] = element;
}

//function for removing element from hashtable
int Remove(int element, int HT[])
{
    if (Search(element, HT) == false)
    {
        cout << "Not Found!!!" << endl;
        return -1;
    }

    int i = 0;
    //breaking condition in case non of the indices left
    while (i * hx2(element) < SIZE * hx2(element) && HT[(hx1(element) + i * hx2(element)) % SIZE] != element)
        i++;

    //whole loop completed
    if (i * hx2(element) == SIZE * hx2(element))
        return false;

    HT[(hx1(element) + i * hx2(element)) % SIZE] = 0;

    return element;
}

int main()
{
    system("cls");
    int HashTable[SIZE] = {0};

    Insert(15, HashTable);
    Insert(25, HashTable);
    Insert(36, HashTable);
    Insert(39, HashTable);
    Insert(45, HashTable);

    //for loading factor <0.5 not more than half size hashtable should be filled

    // Insert(12, HashTable);
    // Insert(32, HashTable);
    // Insert(24, HashTable);
    // Insert(28, HashTable);

    cout << Remove(45, HashTable) << endl;
    cout << Search(45, HashTable) << endl;

    display(HashTable);
}