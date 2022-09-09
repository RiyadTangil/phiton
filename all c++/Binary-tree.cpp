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

void preOrder(treeNode *root, string &chk) //   Left Right Root
{
    if (root == NULL)
        return;
    chk += to_string(root->data);
    preOrder(root->leftChild, chk);
    preOrder(root->rightChild, chk);
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

void printLeftNonLeaves(treeNode *root)
{
    if (root == NULL)
        return;
    if (root->leftChild != NULL)
    {
        cout << root->data << " ";
        printLeftNonLeaves(root->leftChild);
    }
    else if (root->rightChild != NULL)
    {
        cout << root->data << " ";
        printLeftNonLeaves(root->rightChild);
    }
}
void printRightNonLeaves(treeNode *root)
{
    if (root == NULL)
        return;
    if (root->rightChild != NULL)
    {
        cout << root->data << " ";
        printLeftNonLeaves(root->rightChild);
    }
    else if (root->leftChild != NULL)
    {
        cout << root->data << " ";
        printLeftNonLeaves(root->leftChild);
    }
}
void printLeaves(treeNode *root)
{
    if (root == NULL)
        return;
    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        cout << root->data << " ";
        return;
    }
    printLeaves(root->leftChild);
    printLeaves(root->rightChild);
}

void boundaryTraversal(treeNode *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    printLeftNonLeaves(root->leftChild);
    printLeaves(root->leftChild);
    printLeaves(root->rightChild);
    printRightNonLeaves(root->rightChild);
}

int main()
{
    int n;
    cin >> n;
    treeNode *allNodes[n];
    for (int i = 0; i < n; i++)
    {

        allNodes[i] = new treeNode(-1);
    }
    for (int i = 0; i < n; i++)
    {
        int value, left, right;
        cin >> value >> left >> right;
        allNodes[i]->data = value;
        if (left > n - 1 || right > n - 1)
        {
            cout << "Invalid index" << endl;
            break;
        }
        if (left != -1)
            allNodes[i]->leftChild = allNodes[left];
        if (right != -1)
            allNodes[i]->rightChild = allNodes[right];
    }
    // printTree(allNodes[0], 0);
    // string inOrderTraversal = "";
    // string labOrderTraversal = "";
    // inOrder(allNodes[0], inOrderTraversal);
    // cout << "In order traversal: " << inOrderTraversal << endl;
    // cout << endl;
    // preOrder(allNodes[0], labOrderTraversal);
    // cout << " preOrder: " << labOrderTraversal << endl;
    // cout << endl;
    boundaryTraversal(allNodes[0]);
    // int maxValue = levelOrderTraversal(allNodes[0], labOrderTraversal, 2);
    // cout << maxValue << endl;
    return 0;
}