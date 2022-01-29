#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int Searching(int element, Node *head)
{
    bool found = false;

    if (head->next != head)
    {
        Node *ptr = new Node;
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

    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *forth = new Node;
    Node *fifth = new Node;

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