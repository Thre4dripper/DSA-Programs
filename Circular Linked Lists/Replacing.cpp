#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

//fucntion for travering circular linked list
int traverse(node *head)
{
    //function also used to calculate size of circular linked list
    int size = 0;

    node *ptr = new node;
    ptr = head;
    cout << endl
         << "Circular Linked List->";

    //checking of empty circular linked list
    if (ptr->next != ptr)
    {
        //then advancing pointer to the circular linked list
        ptr = head->next;

        //at least one time loop will run (cause condition also ends on start)
        do
        {
            size++;
            cout << ptr->data << " ";
            ptr = ptr->next;

        } while (ptr != head->next);
        //it will loop whole circular linked list to end at start
    }
    else
        cout << "Empty" << endl;

    return size;
}

//function to replace element from start of circulat linked list
int replaceFromStart(int element,node *head)
{
    int initelement;
    //case for empty circular linked list
    if (head->next == head)
        cout << "Empty Circular Linked List" << endl;
    else
    {
        node *ptr = new node;
        ptr = head->next;

        initelement=ptr->data;

        ptr->data = element;
    }

    return initelement;
}

//function to replace element from any index in circular linked list
int replaceFormIndex(int element,node *head, int index, int size)
{
    int initelement;

    if(index>=0 && index<size){
        node *ptr = new node;
        ptr = head->next;

        for (int i = 0; i < index;i++){
            ptr = ptr->next;
        }

        initelement = ptr->data;
        ptr->data = element;
    }
    else
        cout << "Invalid Index"<<endl;

    return initelement;
}

//function to replace element from End in circular linked list
int replaceFromEnd(int element,node *head)
{
    int initelement;

    //case for empty circular linked list
    if (head->next == head)
        cout << "Empty Circular Linked List" << endl;
    else
    {
        node *ptr = new node;
        ptr = head->next;

            while (ptr->next != head->next)
            {
                ptr = ptr->next;
            }
            initelement = ptr->data;
            ptr->data = element;
    }

    return initelement;
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

    size = traverse(head);

    cout << endl
         << replaceFormIndex(10, head,2,size);

    traverse(head);
}