#include <bits/stdc++.h>
using namespace std;
class treeNode
{
public:
    int data;
    treeNode *leftChild;
    treeNode *rightChild;
    treeNode(int value)
    {
        data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};
void spacePrint(int level)
{
    for (int i = 0; i < level; i++)
    {
        cout << "  ";
    }
}
void printTree(treeNode *root, int level)
{

    if (root == NULL)
    {
        return;
    }
    if (root->leftChild == NULL && root->rightChild == NULL)
    {

        cout << root->data << endl;
        return;
    }
    else
    {
        cout << endl;
        spacePrint(level);
        cout << "Root" << root->data << endl;
    }
    if (root->leftChild != NULL)
    {
        spacePrint(level);
        cout << "Left";
        printTree(root->leftChild, level + 1);
    }
    if (root->rightChild != NULL)
    {
        spacePrint(level);
        cout << "right";
        printTree(root->rightChild, level + 1);
    }
}
void inOrder(treeNode *root, string &chk) // Left Root Right
{
    if (root == NULL)
        return;
    inOrder(root->leftChild, chk);
    chk += to_string(root->data);
    inOrder(root->rightChild, chk);
}
// void PreOrder(treeNode *root, string &chk) //  Root Left Right
// {
//     if (root == NULL)
//         return;
//     chk += to_string(root->data);
//     inOrder(root->leftChild, chk);
//     inOrder(root->rightChild, chk);
// }

void PreOrderTraversal(treeNode *root, string &chk) //   Left Right Root
{
    if (root == NULL)
        return;
    chk += to_string(root->data);
    PreOrderTraversal(root->leftChild, chk);
    PreOrderTraversal(root->rightChild, chk);
}
int levelOrderTraversal(treeNode *root, string &chk, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    int level = 0;
    queue<treeNode *> q;
    q.push(root);
    q.push(NULL);
    int max = -999;
    while (!q.empty())
    {
        treeNode *chkNode = q.front();
        q.pop();
        if (chkNode != NULL)
        {
            if (level == k)
            {
                if (max < chkNode->data)
                {
                    max = chkNode->data;
                }
            }
            cout << chkNode->data << " ";
            chk += to_string(chkNode->data);
            if (chkNode->leftChild != NULL)
            {
                q.push(chkNode->leftChild);
            }
            if (chkNode->rightChild != NULL)
            {
                q.push(chkNode->rightChild);
            }
            else
            {
                if (!q.empty())
                {
                    q.push(NULL);
                    level++;
                }
            }

            // if (level == k)
            // {
            //     if (max < chkNode->data)
            //         max = chkNode->data;
            // }
        }
    }
    return max;
}
int searchInOrder(int inOrder[], int current, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (inOrder[i] == current)
        {
            return i;
        }
    }
    return -1;
}
treeNode *buildTreePreIn(int preOrder[], int inOrder[], int start, int end)
{
    static int id = 0;
    int current = preOrder[id];
    id++;
    treeNode *newNode = new treeNode(current);
    if (start == end)
        return newNode;
    int pos = searchInOrder(inOrder, current, start, end);
    newNode->leftChild = buildTreePreIn(preOrder, inOrder, start, pos - 1);
    newNode->rightChild = buildTreePreIn(preOrder, inOrder, pos + 1, end);
    return newNode;
};
int main()
{
    int n;
    cin >> n;
    int preOrder[n], inOrder[n];
    for (int i = 0; i < n; i++)
    {
        cin >> preOrder[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> inOrder[i];
    }
    treeNode *root = buildTreePreIn(preOrder, inOrder, 0, n - 1);
    string chkPre = "";
    PreOrderTraversal(root, chkPre);
    cout << chkPre << endl
         << endl;
    return 0;
}