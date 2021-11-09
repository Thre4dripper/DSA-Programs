#include <iostream>
using namespace std;

//generic stack class implementation using array
template <typename T>
class Stack
{
private:
    int top;
    int size;
    T *arr;

public:
    //constructor for initialising size and top
    Stack(int size)
    {
        top = -1;
        this->size = size;
        arr = (T *)malloc(size * sizeof(T));
    }

    //method for push element in the stack
    void push(T element)
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
            T element = arr[top];
            top--;
            return element;
        }
        else
            cout << "\nStack UnderFlow!!!\n";
    }

    //method for getting top element in the stack
    T peek()
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
    Stack<int> s1(10);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.display();

    Stack<float> s2(10);
    s2.push(10.2);
    s2.push(20.5);
    s2.push(30.6);
    s2.push(40.4);
    s2.display();

    Stack<char> s3(10);
    s3.push('a');
    s3.push('b');
    s3.push('c');
    s3.push('d');

    s3.display();
}