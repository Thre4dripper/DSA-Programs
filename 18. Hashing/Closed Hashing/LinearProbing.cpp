#include <iostream>
using namespace std;

//size of hash table
#define SIZE 10

//function for printing whole hash table
void display(int HT[])
{
    for (int i = 0; i < SIZE; i++)
    {
        if (HT[i] != 0)
            cout << HT[i] << " ";
    }
}

//function for linear probing
int probe(int HT[], int index)
{
    int i = 0;

    //increments value until finds empty space
    while (i < SIZE && HT[(index + i) % SIZE] != 0)
        i++;

    //whole loop completed
    if (i == SIZE)
        return -1;
    return (index + i) % SIZE;
}

//hash function
int hx(int HT[], int x)
{
    int index = x % SIZE;

    if (HT[index] != 0)
        index = probe(HT, index);

    return index;
}

//function for searching element in hashtable
bool Search(int element, int HT[])
{
    int index = element % SIZE;

    int i = 0;
    while (i < SIZE && HT[(index + i) % SIZE] != element)
        i++;

    if (i == SIZE)
        return false;

    return true;
}

//function to insert element in hash table
void Insert(int element, int HT[])
{
    int index = hx(HT, element);

    if (Search(element, HT) == true)
        return;

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

    int index = hx(HT, element);
    int i = 0;
    while (i < SIZE && HT[(index + i) % SIZE] != element)
        i++;

    HT[(index + i) % SIZE] = 0;

    return element;
}

int main()
{
    system("cls");

    int HashTable[SIZE] = {0};
    Insert(15, HashTable);
    Insert(25, HashTable);
    Insert(21, HashTable);
    Insert(35, HashTable);
    Insert(24, HashTable);
    Insert(3, HashTable);
    // Insert(22, HashTable);
    // Insert(02, HashTable);
    // Insert(4, HashTable);
    // Insert(5, HashTable);

    cout << Remove(35, HashTable) << endl;
    cout << Search(35, HashTable) << endl;

    display(HashTable);
}