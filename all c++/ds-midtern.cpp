#include <bits/stdc++.h>
using namespace std;
// class doublyNode
// {
// public:
//     int value;
//     doublyNode *next;
//     doublyNode *prev;
//     // Constructor Creation
//     doublyNode(int val)
//     {
//         value = val;
//         next = NULL;
//         prev = NULL;
//     }
// };

// void insertAtTail(doublyNode *&head, int val, int val2, int idx)
// {
//     doublyNode *newNode = new doublyNode(val);
//     // null|2|null address is 3000
//     if (head == NULL)
//     {
//         head = newNode;
//         return;
//     }
//     doublyNode *temp = head;
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }
//     temp->next = newNode;
//     newNode->prev = temp;
// }

main()
{
    // doublyNode *head = NULL;

    // for (int i = 0; i < size; i++)
    // {
    //     int n, n2;
    //     cin >> n >> n2;
    //     insertAtTail(head, n, n2, i);
    // }
    int size;
    cin >> size;
    int arr[size];
    int arr2[size];
    int arr2[size];
    int pre[100];
    int next[100];
    for (int i = 0; i < size; i++)
    {
        cin >> pre[i];
        cin >> next[i];
    }

    return 0;
}