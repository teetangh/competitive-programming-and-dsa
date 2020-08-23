#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};
template <typename T>
class Stack
{
    Node<T> *head;
    int size; // number of elements prsent in stack

public:
    Stack()
    {
        head = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void push(T element)
    {
        Node<T> *temp = new Node<T>(element);
        temp->next = head;
        head = temp;
        size++;
    }

    T pop()
    {
        // Return 0 if stack is empty. Don't display any other message
        if (isEmpty())
            return 0;
        else
        {
            // Node<T>*temp = head;
            // head = head -> next;
            // size--;
            // return temp->data;
            T ans = head->data;
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            size--;
            return ans;
        }
    }

    T top()
    {
        // Return 0 if stack is empty. Don't display any other message
        if (isEmpty())
            return 0;
        else
            return head->data;
    }
};

