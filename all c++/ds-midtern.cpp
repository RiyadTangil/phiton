#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
    Node *Pre;
    // Constructor Creation
    Node(int val)
    {
        value = val;
        Next = NULL;
        Pre = NULL;
    }
};
struct Test
{
    int position[1000];
};
void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    // cout << " temp=> " << temp << " temp->Next=> " << temp->Next << "head=>" << head << endl;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }

    newNode->Pre = temp;
    temp->Next = newNode;
}
void doublyReverse(Node *&head)
{
    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    while (temp != NULL)
    {
        cout << temp->value;
        if (temp->Pre != NULL)
            cout << " ->";
        temp = temp->Pre;
    }
}
void display(Node *n)
{
    while (n != NULL)
    {
        cout << n->value;
        if (n->Next != NULL)
            cout << " ->";
        n = n->Next;
    }
}
void printExCancel(Node *head)
{
    Node *start = head;
    Node *end;

    while (start)
    {
        bool mod = false;
        int sum = 0;
        end = start;
        while (end)
        {
            sum += end->value;
            if (sum == 0)
            {
                start = end;
                mod = true;
                break;
            }
            end = end->Next;
        }
        if (mod == false)
        {
            // push to new list
            printf("%d\n", start->value);
        }
        // else {
        //     call funtion to delete from start to end
        // }
        start = start->Next;
    }
}

int main()
{
    Node *head = NULL;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        insertAtTail(head, num);
    }
    display(head);
    cout << endl;
    // doublyReverse(head);
    printExCancel(head);
    cout << endl;

    return 0;
}
