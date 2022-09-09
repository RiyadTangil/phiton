#include <bits/stdc++.h>
using namespace std;
template <typename N>
class NodeQueue
{
public:
    N value;
    NodeQueue *next;
    NodeQueue(N val)
    {
        value = val;
        next = NULL;
    }
};
template <typename Q>
class Queue
{
    NodeQueue<Q> *front;
    NodeQueue<Q> *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    void push(Q val)
    {
        NodeQueue<Q> *newNode = new NodeQueue<Q>(val);
        if (front == NULL)
        {
            front = newNode;
            rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = rear->next;
    }
    Q pop()
    {
        Q chk;
        if (rear == NULL)
        {
            cout << "Queue Underflow : There is no elements in the Queue" << endl;
            return chk;
        }
        NodeQueue<Q> *delNode;
        delNode = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        chk = delNode->value;
        delete delNode;
        return chk;
    }
    int Front()
    {
        Q chk;
        chk = front->value;
        return chk;
    }
    int Back()
    {
        Q chk;
        chk = rear->value;
        return chk;
    }
    bool empty()
    {
        if (front == NULL && rear == NULL)
            return true;
        else
            return false;
    }
};
