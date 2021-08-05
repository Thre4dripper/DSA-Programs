#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

//fucntion for travering circular linked list
void traverse(node *head)
{
    node *ptr = new node;
    ptr = head;

    //checking of empty circular linked list
    if (ptr->next != ptr)
    {
        //then advancing pointer to the circular linked list
        ptr = head->next;

        //at least one time loop will run (cause condition also ends on start)
        do
        {
            cout << ptr->data << " ";
            ptr = ptr->next;

        } while (ptr != head->next);
        //it will loop whole circular linked list to end at start
    }
    else
        cout << "Empty Linked List" << endl;
}

int main()
{
    system("cls");

    node *head = new node;
    node *second = new node;
    node *third = new node;
    node *forth = new node;
    node *fifth = new node;

    head->next = head;

    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = forth;

    forth->data = 40;
    forth->next = fifth;

    fifth->data = 50;
    fifth->next = second;

    traverse(head);
}