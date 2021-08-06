#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

int Searching(int element, node *head)
{
    bool found = false;

    if (head->next != head)
    {
        node *ptr = new node;
        ptr = head->next;

        while (ptr->next!=head->next)
        {
            if(ptr->data==element){
                found = true;
                break;
            }
            else
            ptr = ptr->next;
        }
        
    }
    else
        cout << "Empty Circular Linked List" << endl;

    return found;
}

int main()
{
    system("cls");

    node *head = new node;
    node *second = new node;
    node *third = new node;
    node *forth = new node;
    node *fifth = new node;

    int size;

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

    cout << endl
         << Searching(20, head);
}