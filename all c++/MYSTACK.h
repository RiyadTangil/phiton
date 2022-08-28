#include <bits/stdc++.h>
using namespace std;

template <typename N>
class Node
{
public:
    N value;
    Node *next;
    Node *prev;
    // Constructor Creation
    Node(N val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
};
template <typename S>
class Stack
{
    Node<S> *head;
    Node<S> *top;
    Node<S> *mid;
    int Count = 0;

public:
    Stack()
    {
        head = NULL;
        top = NULL;
        mid = NULL;
    }
    // Push
    void push(S val)
    {
        Node<S> *newNode = new Node<S>(val);
        if (head == NULL)
        {
            head = top = mid = newNode;
            Count++;
            return;
        }
        // as we have at list one node
        top->next = newNode;
        newNode->prev = top;
        if (Count % 2 == 1)
        {
            mid = mid->next;
        }
        Count++;
        top = newNode;
    }
    // Pop
    S pop()
    {
        Node<S> *delNode;
        delNode = top;
        S chk;
        if (head == NULL)
        {
            cout << "Stack Under Flow" << endl;
            return chk;
        }
        if (top == head)
        {
            head = top = mid = NULL;
        }
        else
        {
            top = delNode->prev;
            top->next = NULL;
            if (Count % 2 == 0)
            {
                mid = mid->prev;
            }
        }
        chk = delNode->value;
        delete delNode;
        Count--;
        return chk;
    }
    // Empty
    bool empty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }
    // Top
    S Top()
    {
        S chk;
        if (top == NULL)
        {

            cout << "Stock UnderFlow| There is no value" << endl;
        }

        else
            chk = top->value;
        return chk;
    }
    // sizeof
    int findMiddle()
    {
        if (Count == 0)
        {
            return -1;
        }
        return mid->value;
    }
    int size()
    {
        return Count;
    }
};
