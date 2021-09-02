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
        cout << "Empty Linked List" << endl;

    return size;
}

//function to insert element at start of circulat linked list
void insertAtStart(int element, node **head)
{
    node *ptr = new node;
    ptr->data = element;

    //when circular linked list is empty, it will create one
    if ((*head)->next == (*head))
    {
        ptr->next = ptr;
        (*head)->next = ptr;
    }
    //storing of element in created circular linked list
    else
    {
        node *p = new node;
        p = (*head)->next;

        while (p->next != (*head)->next)
        {
            p = p->next;
        }

        ptr->next = (*head)->next;
        (*head)->next = ptr;
        p->next = ptr;
    }
}

//function to insert element at any index in circular linked list
void insertAtIndex(int element, node **head, int index, int *size)
{

    //index should be in size range
    if (index <= *size && index >= 0)
    {
        node *ptr = new node;
        ptr->data = element;

        node *p = new node;
        p = (*head)->next;

        //two cases when index=0
        if (index == 0)
        {
            //when circular linked list is empty, it will create one
            if ((*head)->next == *head)
            {
                ptr->next = ptr;
                (*head)->next = ptr;
            }
            //inserting element at '0' in already created circular linked list
            else
            {
                while (p->next != (*head)->next)
                {
                    p = p->next;
                }

                ptr->next = (*head)->next;
                (*head)->next = ptr;
                p->next = ptr;
            }
        }
        //insertion at index other than 0 same procedure will be followed now on
        else
        {
            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }

            ptr->next = p->next;
            p->next = ptr;
        }
        (*size)++;
    }
    else
        cout << "Invalid Index";
}

//function to insert element at End in circular linked list
void insertAtEnd(int element, node **head)
{
    node *ptr = new node;
    ptr->data = element;

    //condition for empty circular linked list
    if ((*head)->next == *head)
    {
        ptr->next = ptr;
        (*head)->next = ptr;
    }
    //for filled circular linked list
    else
    {
        node *p = new node;

        p = (*head)->next;
        while (p->next != (*head)->next)
        {
            p = p->next;
        }

        ptr->next = p->next;
        p->next = ptr;
    }
}

int main()
{
    system("cls");

    node *head = new node;
    head->next = head;
    int size;

    size = traverse(head);

    insertAtIndex(10, &head, 0, &size);
    insertAtIndex(20, &head, 1, &size);
    insertAtIndex(30, &head, 0, &size);

    size = traverse(head);
}