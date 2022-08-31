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
struct Test
{
    int position[1000];
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
    // cout << " temp=> " << temp << " temp->Next=> " << temp->Next << "head=>" << head << endl;
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
Test searchByValueDuplicateReturn(Node *&head, int key)
{
    Node *temp = head;
    Test T;
    int k = 1;
    int count = 1;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            T.position[k] = count;
            k++;
        }
        temp = temp->Next;
        count++;
    }
    T.position[0] = k;
    return T;
}
void searchByValueUnique(Node *&head, int searchValue, int value)
{
    int position;
    position = searchByUniqueValue(head, searchValue);
    insertAtPosition(head, value, position + 1);
}
void deletionAtHead(Node *&head)
{
    Node *temp = head;
    if (temp->Next != NULL)
    {
        head = temp->Next;
        delete temp;
    }
    else
    {
        cout << "There is No Value in The Linked list" << endl;
    }
}

void deletionAtTail(Node *&head)
{
    Node *temp = head;
    if (temp->Next != NULL && temp->Next != NULL)
    {
        while (temp->Next->Next != NULL)
        {
            temp = temp->Next;
        }
        Node *delNode = temp->Next;
        temp->Next = NULL;
        delete delNode;
    }
    else
    {
        if (temp == NULL)
        {

            cout << "There is No Value in The Linked list" << endl;
        }
        else
        {
            deletionAtHead(head);
        }
    }
}

void deletionAtSpecifiedPosition(Node *&head, int position)
{
    Node *temp = head;
    if (position <= countLength(head))
    {
        if (position == 1)
            deletionAtHead(head);
        else if (position == countLength(head))
            deletionAtTail(head);
        else
        {
            int i = 1;
            while (i < position - 1)
            {
                temp = temp->Next;
                i++;
            }
            Node *delNode = temp->Next;
            temp->Next = delNode->Next;
            delete delNode;
        }
    }
    else
    {
        // Position out of range;
        cout << "Position out of Bounds";
    }
}

void deletionByValueUnique(Node *&head, int value)
{
    int position;
    position = searchByUniqueValue(head, value);
    if (position == -1)
        cout << "Value not found in the Linked list" << endl;
    else
    {
        deletionAtSpecifiedPosition(head, position);
    }
}
Node *reverseNonRecursive(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    if (head == NULL)
    {
        cout << "The Linked List is Empty!" << endl;
        return head;
    }
    Node *next = head->Next;
    while (true)
    {
        current->Next = prev;
        prev = current;
        current = next;
        if (current == NULL)
            break;
        next = next->Next;
    }
    return prev;
}

Node *reverseRecursive(Node *&head)
{
    // base case,
    if (head == NULL || head->Next == NULL)
    {
        if (head == NULL)
            cout << "The Linked list is empty" << endl;
        return head;
    }
    Node *newHead = reverseRecursive(head->Next);
    head->Next->Next = head;
    head->Next = NULL;
    return newHead;

    // A,X,Y,Z
    // Z->Y->NULL return korlam Z ke
    // Z->Y->X->NULL return korlam Z ke
    // Z->Y->X->A->NULL return korlam Z ke
}

main()
{
    Node *head = NULL;
    int n;
    cout << "Choice 1:Insertion at Head" << endl;
    int choice = 2;
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter the Value : ";
            cin >> n;
            insertAtHead(head, n);
            break;
        case 2:
            cout << "Enter the Value for tail: ";
            cin >> n;
            insertAtTail(head, n);
            break;
        case 3:
            cout << "Enter the Value : ";
            cin >> n;
            int pos;
            cin >> pos;
            insertAtPosition(head, n, pos);
            break;
        case 4:
            cout << "Enter the Value : ";
            cin >> n;
            cout << "Entered position " << searchByUniqueValue(head, n) << endl;
            break;
        case 5:
            cout << "Entered the value to search ";
            int value;
            cin >> value;
            // searchByDuplicate(head, value);
            Test T;
            T = searchByValueDuplicateReturn(head, value);
            if (T.position[0] == 1)
            {
                cout << "The Search Value is not yet in the list!" << endl;
            }
            else
            {
                int size = T.position[0];
                cout << "The vale is found at position ";
                for (int i = 1; i < size; i++)
                {
                    cout << T.position[i];
                    if (i < size - 1)
                        cout << ", ";
                }
                cout << endl;
            }
            break;
        case 6:
            cout << "Enter the Value to search: ";
            int searchValue;
            cin >> searchValue;
            cout << "Enter the value to insert";
            cin >> n;
            searchByValueUnique(head, searchValue, n);

            cout << "Entered position " << searchByUniqueValue(head, n) << endl;
            break;
        case 7:

            deletionAtHead(head);
            break;
        case 8:

            deletionAtTail(head);
            break;
        case 9:
            if (head == NULL)
            {
                cout << "There is No Value in The Link List" << endl;
                break;
            }
            cout << "Enter The Desired Position ";
            int position;
            cin >> position;
            deletionAtSpecifiedPosition(head, position);
            display(head);
            cout << endl;
            break;
        case 10:
            int val;
            cout << "Enter The Desired Value ";
            cin >> val;
            deletionByValueUnique(head, val);
            break;
        case 11:
            head = reverseNonRecursive(head);
            break;
        case 12:
            // https://www.youtube.com/watch?v=bjtMCwy_LMA
            head = reverseRecursive(head);
            break;

        default:
            break;
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
