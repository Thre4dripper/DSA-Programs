#include <iostream>
using namespace std;

//stack class implementation using linked list
class Stack
{

private:
    //structure for stack node
    struct Node
    {
        int data;
        Node *next;
    };

    Node *top = NULL;
    int size = 0;

public:
    //method for pushing element in the stack
    void push(int element)
    {
        Node *ptr = new Node;
        ptr->data = element;
        ptr->next = top;
        top = ptr;

        size++;
    }

    //method for removing element from stack
    int pop()
    {
        if (top != NULL)
        {
            Node *ptr = top;

            int element = ptr->data;
            top = top->next;

            delete ptr;
            size--;

            return element;
        }
        else
            cout << "\nStack UnderFlow!!!\n";
    }

    //method for finding top element in the stack
    int peek()
    {
        if (top != NULL)
            return top->data;
        else
            cout << "\nEmpty Stack!!!\n";

        return -1;
    }

    //method for printing all the element from the stack
    void display()
    {

        cout << "\n[";
        Node *ptr = top;

        while (ptr != NULL)
        {
            cout << ptr->data;
            if (ptr->next != NULL)
                cout << " | ";
            ptr = ptr->next;
        }

        cout << "]";
    }

    //method for finding stack is empty or not
    bool isEmpty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }

    //there is no isFull function in case of linked list because of dynamic allocation

    //method for finding size of the stack
    int Size()
    {
        return size;
    }
};

int main()
{
    system("cls");

    //stack class object
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.pop();

    s.display();
}
