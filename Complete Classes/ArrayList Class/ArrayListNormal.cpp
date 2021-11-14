#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//ArrayList class implementation with all basic operations
class List
{
private:
    //structure for each node;
    struct node
    {
        int data;
        node *next;
        node *prev;
    };

    node *front = NULL;
    node *rear = NULL;
    int size = 0;

public:
    //method for adding an element to the end of List
    List &add(int element)
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
    List &add(int index, int element)
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

    int get(int index)
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
    List &set(int index, int element)
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
    bool contains(int element)
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
    int indexof(int element)
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
    int lastIndexof(int element)
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
            int temp;

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

    //method for finding max element from the list
    int max()
    {
        node *ptr = front;
        int max = ptr->data;
        while (ptr != NULL)
        {
            if (max < ptr->data)
                max = ptr->data;
            ptr = ptr->next;
        }

        return max;
    }

    //method for finding min element from the list
    int min()
    {
        node *ptr = front;
        int min = ptr->data;
        while (ptr != NULL)
        {
            if (min > ptr->data)
                min = ptr->data;
            ptr = ptr->next;
        }

        return min;
    }

    //method for finding sum of all elements in the list
    int sum()
    {
        node *ptr = front;
        int sum = 0;
        while (ptr != NULL)
        {
            sum += ptr->data;
            ptr = ptr->next;
        }

        return sum;
    }

    //method for finding average of all elements in the list
    float avg()
    {
        return 1.0 * sum() / size;
    }

    //method for swaping two elements in the list
    List &swap(int index1, int index2)
    {
        if (index1 >= 0 && index1 < size && index2 >= 0 && index2 < size)
        {
            node *p1 = front;
            node *p2 = front;

            for (int i = 0; i < index1; i++)
                p1 = p1->next;

            for (int i = 0; i < index2; i++)
                p2 = p2->next;

            int temp = p1->data;
            p1->data = p2->data;
            p2->data = temp;
        }
        else
            cout << "\nIndex Out of Bounds!!!\n";

        return *this;
    }

    //method for left rotation of list
    List &leftRotate(int count)
    {
        node *ptr;
        int temp;

        for (int i = 1; i <= count; i++)
        {
            ptr = front;
            temp = ptr->data;
            remove(0);
            add(temp);
        }
        return *this;
    }

    //method for right rotation of list
    List &rightRotate(int count)
    {
        node *ptr;
        int temp;

        for (int i = 1; i <= count; i++)
        {
            ptr = rear;
            temp = ptr->data;
            remove(size - 1);
            add(0, temp);
        }
        return *this;
    }

    //method for sort list
    List &Sort()
    {
        node *ptr = front;

        for (int i = 0; ptr->next != NULL; i++)
        {
            if (ptr->data < ptr->next->data)
                ptr = ptr->next;
            else
            {
                node *p = ptr->next;
                for (int j = i + 1; p->prev != NULL && p->data < p->prev->data; j--)
                {
                    swap(j, j - 1);
                    p = p->prev;
                }
                ptr = ptr->next;
            }
        }

        return *this;
    }
};

int main()
{
    system("cls");

    //declaration of Object of List
    List list;
    list.add(10).add(20).add(30);
    list.add(0);
    list.add(75);
    list.add(50);
    list.add(60);
    list.Sort().display();
}