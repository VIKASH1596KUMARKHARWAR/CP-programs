#include <iostream>
#include <queue>
#include "2_Tree.h"
using namespace std;

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter num of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

// Function to print the tree in level order
void printLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int> *> pendingNode;
    pendingNode.push(root);
    while (!pendingNode.empty())
    {
        TreeNode<int> *front = pendingNode.front();
        pendingNode.pop();
        cout << front->data << ":";

        for (int i = 0; i < front->children.size(); i++)
        {
            if (i < ((front->children.size()) - 1))
            {
                cout << front->children[i]->data << ",";
            }
            else
            {
                cout << front->children[i]->data;
            }
            pendingNode.push(front->children[i]);
        }
        cout << "\n";
    }
}

int numNodestotal(TreeNode<int> *root)
{
    if (root == nullptr)
        return 0;
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numNodestotal(root->children[i]);
    }
    return ans;
}

void printAtLevelK(TreeNode<int> *root, int k)
{
    if (root == nullptr)
        return;
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k - 1);
    }
}

void preOprder(TreeNode<int> *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preOprder(root->children[i]);
    }
}
void printTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;

    // aab hame traverse kr ke jaana bhi both padega next level mein  by recursion
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
};
~TreeNode()
{
    for (int i = 0; i < children.size(); ++i)
    {
        delete children[i];
    }
}

// 1 3 2 3 4 2 5 6 7 8 0 0 0 0 1 9 0
int main()
{
    /* TreeNode<int> *root = new TreeNode(1);
     TreeNode<int> *node1 = new TreeNode(2); // independent nodes
     TreeNode<int> *node2 = new TreeNode(3);
     root->children.push_back(node1);
     root->children.push_back(node2); */

    TreeNode<int> *root = takeInputLevelWise();
    // printTree(root);
    printLevelWise(root);
    int ans = numNodestotal(root);
    cout << "total nodes: " << ans << endl;
    int k;
    cout << " enter the value of k(the level u wanna print )" << endl;
    cin >> k;
    printAtLevelK(root, k);
}