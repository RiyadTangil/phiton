#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
    // Constructor Creation
    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};
void insertAtHead(Node *&head, int val);
void insertAtTail(Node *&head, int val);
void display(Node *n);
void insertAtPosition(Node *&head, int val, int pos);
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->Next = head;
    Node *temp = head;
    head = newNode;
}
int searchByUniqueValue(Node *&head, int val);
void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
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
int countLength(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->Next;
    }
    return count;
}
void insertAtPosition(Node *&head, int val, int pos)
{
    int i = 0;
    Node *temp = head;
    while (i <= pos - 2)
    {
        temp = temp->Next;
        i++;
    }
    Node *newNode = new Node(val);
    newNode->Next = temp->Next;
    temp->Next = newNode;
}
int searchByUniqueValue(Node *&head, int key)
{
    Node *temp = head;
    int count = 1;
    if (temp == NULL)
    {
        return -1;
    }
    while (temp->value != key)
    {
        if (temp->Next == NULL)
        {
            return -1;
        }
        temp = temp->Next;
        count++;
    }
    return count;
}
int searchByDuplicate(Node *&head, int key)
{
    Node *temp = head;
    int size = 0;
    size = countLength(head);
    int position[size + 1], k = 1;
    int count = 1;
    int flag = 0;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            position[k] = count;
            k++;
            flag = 1;
        }
        temp = temp->Next;
        count++;
    }
    if (flag == 0)
        cout << "The Search value is not yet in the list" << endl;
    else
    {
        position[0] = k;
        cout << "The value is found at position";
        for (int i = 1; i <= position[0]; i++)
        {
            cout << position[i];
            if (i < position[0] - 1)
                cout << " ,";
        }
        cout << endl;
    }
}
main()
{
    Node *head = NULL;
    int n;
    cout << "Choice 1:Insertion at Head" << endl;
    int choice = 2;
    while (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5)
    {
        cout << "Enter the Value :";
        cin >> n;
        if (choice == 1)
            insertAtHead(head, n);
        else if (choice == 2)
            insertAtTail(head, n);
        else if (choice == 3)
        {
            cout << "Enter position";
            int pos;
            cin >> pos;
            insertAtPosition(head, n, pos);
        }
        else if (choice == 4)
        {

            cout << "Entered position " << searchByUniqueValue(head, n) << endl;
        }
        else if (choice == 5)
        {

            cout << "Entered the value to search  ";
            int value;
            cin >> value;
            searchByDuplicate(head, value);
        }
        cout << "Next Choice ";
        cin >> choice;
    }

    // char choice = 'Y';
    // while (choice == 'Y')
    // {
    //     cout << "Enter the value:";
    //     cin >> n;
    //     insertAtTail(head, n);
    //     cout << "do you want to Continue (Y/N)";
    //     cin >> choice;
    // }
    display(head);
    cout << endl;
    cout << "length of linked list is " << countLength(head);

    return 0;
}