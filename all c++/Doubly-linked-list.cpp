#include <bits/stdc++.h>
using namespace std;

class doublyNode
{
public:
    int value;
    doublyNode *next;
    doublyNode *prev;
    // Constructor Creation
    doublyNode(int val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
};

struct Test
{
    int position[1000];
};

void insertAtHead(doublyNode *&head, int val);
void insertAtTail(doublyNode *&head, int val);
void display(doublyNode *n);
void insertAtPosition(doublyNode *&head, int val, int pos);
void insertAtHead(doublyNode *&head, int val)
{
    doublyNode *newNode = new doublyNode(val);
    head->prev = newNode;
    newNode->next = head;
    doublyNode *temp = head;
    head = newNode;
}
int searchByUniqueValue(doublyNode *&head, int val);
void insertAtTail(doublyNode *&head, int val)
{
    doublyNode *newNode = new doublyNode(val);
    // null|2|null address is 3000
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    doublyNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void display(doublyNode *n)
{
    while (n != NULL)
    {
        cout << n->value;
        if (n->next != NULL)
            cout << " ->";
        n = n->next;
    }
}

void displayReverse(doublyNode *head)
{
    doublyNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        cout << temp->value;
        if (temp->prev != NULL)
            cout << "--->";
        temp = temp->prev;
    }
    cout << endl
         << endl;
}

int countLength(doublyNode *&head)
{
    int count = 0;
    doublyNode *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void insertAtPosition(doublyNode *&head, int val, int pos)
{
    int i = 0;
    doublyNode *temp = head;
    while (i <= pos - 2)
    {
        temp = temp->next;
        i++;
    }
    doublyNode *newNode = new doublyNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
}
int searchByUniqueValue(doublyNode *&head, int key)
{
    doublyNode *temp = head;
    int count = 1;
    if (temp == NULL)
    {
        return -1;
    }
    while (temp->value != key)
    {
        if (temp->next == NULL)
        {
            return -1;
        }
        temp = temp->next;
        count++;
    }
    return count;
}
int searchByDuplicate(doublyNode *&head, int key)
{
    doublyNode *temp = head;
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
        temp = temp->next;
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
Test searchByValueDuplicateReturn(doublyNode *&head, int key)
{
    doublyNode *temp = head;
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
        temp = temp->next;
        count++;
    }
    T.position[0] = k;
    return T;
}
void searchByValueUnique(doublyNode *&head, int searchValue, int value)
{
    int position;
    position = searchByUniqueValue(head, searchValue);
    insertAtPosition(head, value, position + 1);
}
void deletionAtHead(doublyNode *&head)
{
    doublyNode *temp = head;
    if (temp->next != NULL)
    {
        head = temp->next;
        delete temp;
    }
    else
    {
        cout << "There is No Value in The Linked list" << endl;
    }
}

void deletionAtTail(doublyNode *&head)
{
    doublyNode *temp = head;
    if (temp->next != NULL && temp->next != NULL)
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        doublyNode *delNode = temp->next;
        temp->next = NULL;
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
void deletionAtSpecifiedPosition(doublyNode *&head, int position)
{
    doublyNode *temp = head;
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
                temp = temp->next;
                i++;
            }
            doublyNode *delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;
        }
    }
    else
    {
        // Position out of range;
        cout << "Position out of Bounds";
    }
}
void deletionByValueUnique(doublyNode *&head, int value)
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
doublyNode *reverseNonRecursive(doublyNode *&head)
{
    doublyNode *prev = NULL;
    doublyNode *current = head;
    if (head == NULL)
    {
        cout << "The Linked List is Empty!" << endl;
        return head;
    }
    doublyNode *newNext = head->next;
    while (true)
    {
        current->next = prev;
        prev = current;
        current = newNext;
        if (current == NULL)
            break;
        newNext = newNext->next;
    }
    return prev;
}

doublyNode *reverseRecursive(doublyNode *&head)
{
    // base case,
    if (head == NULL || head->next == NULL)
    {
        if (head == NULL)
            cout << "The Linked list is empty" << endl;
        return head;
    }
    doublyNode *newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;

    // A,X,Y,Z
    // Z->Y->NULL return korlam Z ke
    // Z->Y->X->NULL return korlam Z ke
    // Z->Y->X->A->NULL return korlam Z ke
}
int findMid(doublyNode *&head)
{
    // Case -1:Head Empty
    if (head == NULL)
        return -1;
    doublyNode *show = head;
    doublyNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        show = show->next;
        fast = fast->next->next;
    }
    return show->value;
}
void makeCycle(doublyNode *&head, int pos)
{
    doublyNode *temp = head;
    doublyNode *startNode;
    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
            startNode = temp;
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}
bool detectCycle(doublyNode *&head)
{
    doublyNode *slow = head;
    doublyNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow->next == fast->next)
            return true;
    }
    return false;
}

void removeCycle(doublyNode *&head)
{
    doublyNode *slow = head;
    doublyNode *fast = head;
    // Step 1; fast=slow
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    // step 2 Re Initiallization of fast
    fast = head;

    // setp 3: fast ->Next =slow ->Next
    while (fast->next != slow->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    // step 4
    slow->next = NULL;
}
main()
{
    doublyNode *head = NULL;
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
            cout << "Enter the Value : ";
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
        case 13:

            int mid;
            mid = findMid(head);
            if (mid)
                cout << "The mid is " << mid << endl;
            else
                cout << "The Linked list is empty" << endl;
            break;
        case 14:
            // https://www.youtube.com/watch?v=bjtMCwy_LMA
            cout << "Enter your expect cycle position" << endl;
            cin >> position;
            makeCycle(head, position);
            break;
        case 15:
            bool cycleStatus;
            cycleStatus = detectCycle(head);
            if (cycleStatus == true)
                cout << "There is cycle in the list" << endl;
            else
                cout << "There is no cycle in the list" << endl;

            break;
        case 16:
            cycleStatus = detectCycle(head);
            if (cycleStatus == true)
                removeCycle(head);
            else
                cout << "There is no cycle in the list" << endl;

            break;

        default:
            break;
        }

        cout << "next Choice ";
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
    displayReverse(head);
    cout << endl;
    cout << "length of linked list is " << countLength(head);

    return 0;
}
