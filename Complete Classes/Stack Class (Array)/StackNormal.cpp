#include <iostream>
using namespace std;

//stack class implementation using array
class Stack
{
private:
    int top;
    int size;
    int *arr;

public:
    //constructor for initialising size and top
    Stack(int size)
    {
        top = -1;
        this->size = size;
        arr = (int *)malloc(size * sizeof(int));
    }

    //method for push element in the stack
    void push(int element)
    {
        if (top < size - 1)
        {
            this->top++;
            this->arr[top] = element;
        }
        else
            cout << "\nStack Overflow!!!\n";
    }

    //method for pop element from the stack
    int pop()
    {

        if (top != -1)
        {
            int element = arr[top];
            top--;
            return element;
        }
        else
            cout << "\nStack UnderFlow!!!\n";
    }

    //method for getting top element in the stack
    int peek()
    {
        if (top != -1)
            return arr[top];
        else
            cout << "\nEmpty Stack!!!\n";

        return -1;
    }

    //method for display entire stack
    void display()
    {
        cout << "\n[";

        for (int i = top; i >= 0; i--)
        {
            cout << arr[i];
            if (i != 0)
                cout << " | ";
        }

        cout << "]";
    }

    //method for checking stack is empty or not
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    //method for checking stack is full or not
    bool isFull()
    {
        if (top == size - 1)
            return true;
        else
            return false;
    }

    //method for getting size of stack
    int Size()
    {
        return top + 1;
    }
};

int main()
{
    system("cls");

    //class int type object declaration
    Stack s(10);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.display();
}