#include <iostream>
using namespace std;

//generic stack class implementation using linked list
template<typename T>
class Stack
{
private:
    //structure for stack node
    struct Node
    {
        T data;
        Node *next;
    };

    Node *top = NULL;
    int size = 0;

public:
    //method for pushing element in the stack
    void push(T element)
    {
        Node *ptr = new Node;
        ptr->data = element;
        ptr->next = top;
        top = ptr;

        size++;
    }

    //method for removing element from stack
    T pop()
    {
        if (top != NULL)
        {
            Node *ptr = top;

            T element = ptr->data;
            top = top->next;

            delete ptr;
            size--;

            return element;
        }
        else
            cout << "\nStack UnderFlow!!!\n";
    }

    //method for finding top element in the stack
    T peek()
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

    //stack class objects

    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.pop();
    s1.display();

    Stack<float> s2;
    s2.push(10.3);
    s2.push(20.5);
    s2.push(30.54);
    s2.push(40);
    s2.display();

    Stack<char> s3;
    s3.push('a');
    s3.push('b');
    s3.push('c');
    s3.push('d');

    s3.display();
}
