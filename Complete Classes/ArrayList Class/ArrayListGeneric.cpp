#include <iostream>
using namespace std;

//ArrayList class implementation with all basic operations
template <typename T>
class List
{
private:
    //structure for each node;
    struct node
    {
        T data;
        node *next;
        node *prev;
    };

    node *front = NULL;
    node *rear = NULL;
    int size = 0;

public:
    //method for adding an element to the end of List
    List &add(T element)
    {
        node *ptr = new node;
        ptr->data = element;
        ptr->next = NULL;

        if (front == NULL)
        {
            front = rear = ptr;
            ptr->prev = NULL;
        }
        else
        {
            rear->next = ptr;
            ptr->prev = rear;
            rear = ptr;
        }

        size++;

        return *this;
    }

    //method for adding an element to a given index of List
    List &add(int index, T element)
    {
        if (index < 0 || index > size)
        {
            cout << "\nIndex out of Bounds!!!\n";
            return *this;
        }
        else if (index == 0)
        {
            node *ptr = new node;
            ptr->data = element;

            ptr->next = front;
            ptr->prev = NULL;
            front->prev = ptr;
            front = ptr;
            size++;
            return *this;
        }
        else if (index == size)
        {
            return add(element);
        }

        node *ptr = new node;
        ptr->data = element;

        node *p = front;

        for (int i = 0; i < index - 1; i++)
            p = p->next;

        ptr->next = p->next;
        ptr->prev = p;
        p->next->prev = ptr;
        p->next = ptr;
        size++;

        return *this;
    }

    //method for removing an element from the end of List
    List &remove()
    {
        if (size > 0)
        {
            node *ptr = rear;

            if (size > 1)
            {
                rear = rear->prev;
                rear->next = NULL;
            }
            else if (size == 1)
                front = rear = NULL;

            delete ptr;

            size--;
        }
        else
            cout << "\nEmpty List!!\n";

        return *this;
    }

    //method for removing an element from the end of List
    List &remove(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "\nIndex Out of Bounds!!\n";
            return *this;
        }
        else if (index == size - 1)
        {
            return remove();
        }
        else if (index == 0)
        {
            node *ptr = front;

            front = front->next;
            front->prev = NULL;
            delete ptr;
            size--;
            return *this;
        }

        node *p = front;

        for (int i = 0; i < index - 1; i++)
            p = p->next;

        node *ptr = p->next;

        p->next->next->prev = p;
        p->next = p->next->next;

        delete ptr;
        size--;

        return *this;
    }

    //method for displaying all the elements of the list
    List &display()
    {
        node *ptr = front;

        cout << "[";
        while (ptr != NULL)
        {
            cout << ptr->data;
            if (ptr->next != NULL)
                cout << ",";
            ptr = ptr->next;
        }

        cout << "]";

        return *this;
    }

    //method for getting size of the list
    int getSize()
    {
        return size;
    }

    T get(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "\nIndex Out of Bounds!!!\n";
            return -1;
        }
        else if (index == 0)
            return front->data;
        else if (index == size - 1)
            return rear->data;
        else
        {
            node *p = front;

            for (int i = 0; i < index - 1; i++)
                p = p->next;

            return p->next->data;
        }
    }

    //method for replacing an element from a given index in a list
    List &set(int index, T element)
    {
        if (index < 0 || index >= size)
        {
            cout << "\nIndex Out of Bounds!!\n";
            return *this;
        }
        else if (index == 0)
        {
            front->data = element;
            return *this;
        }

        node *p = front;

        for (int i = 0; i < index - 1; i++)
            p = p->next;

        p->next->data = element;

        return *this;
    }

    //method for checking if a element is present or not in the list
    bool contains(T element)
    {
        node *ptr = front;
        while (ptr != NULL)
        {
            if (ptr->data == element)
                return true;
            ptr = ptr->next;
        }

        return false;
    }

    //method for getting first index of an element in the list
    int indexof(T element)
    {
        node *ptr = front;
        for (int i = 0; ptr != NULL; i++)
        {
            if (ptr->data == element)
                return i;

            ptr = ptr->next;
        }

        return -1;
    }

    //method for getting last index of an element in the list
    int lastIndexof(T element)
    {
        node *ptr = rear;
        for (int i = size - 1; ptr != NULL; i--)
        {
            if (ptr->data == element)
                return i;

            ptr = ptr->prev;
        }

        return -1;
    }

    //method for reversing the list
    List &reverse()
    {

        if (size == 0)
        {
            cout << "\Warning!!! Attempting to reverse empty ArrayList\n";
            return *this;
        }

        if (size > 1)
        {
            node *first = front;
            node *last = rear;
            T temp;

            do
            {
                temp = first->data;
                first->data = last->data;
                last->data = temp;

                first = first->next;
                last = last->prev;

            } while (first->next != last && first != last);
        }

        return *this;
    }

    //method for checking if the list is empty or not
    bool isEmpty()
    {
        if (front == NULL)
            return true;
        return false;
    }

    List &clear()
    {
        node *ptr = front;
        front = NULL;
        node *p = front;

        while (p != NULL)
        {
            ptr = p;
            p = p->next;
            delete ptr;
        }

        return *this;
    }
};

int main()
{
    system("cls");

    //declarations of Objects of List
    List<int> list1;
    list1.add(10).add(20).add(30);
    list1.add(40);
    list1.add(50);
    list1.add(50);
    list1.add(60);
    list1.reverse().display();

    List<float> list2;
    list2.add(10.2).add(20.43).add(30.4);
    list2.add(40.54);
    list2.add(50.41);
    list2.add(50.85);
    list2.add(60.36);
    cout << endl;
    list2.reverse().display();

    List<char> list3;
    list3.add('a').add('b').add('c');
    list3.add('d');
    list3.add('e');
    list3.add('f');
    list3.add('g');
    cout << endl;
    list3.reverse().display();
}