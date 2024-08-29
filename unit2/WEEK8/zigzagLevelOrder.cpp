#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
        {
            return result;
        }

        queue<TreeNode *> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                int index = leftToRight ? i : size - 1 - i;
                level[index] = node->val;

                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }

            result.push_back(level);
            leftToRight = !leftToRight;
        }

        return result;
    }
};

// Function to print 2D vector
void printVector(const vector<vector<int>> &vec)
{
    cout << "[";
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << "[";
        for (int j = 0; j < vec[i].size(); ++j)
        {
            cout << vec[i][j];
            if (j < vec[i].size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < vec.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main()
{
    // Example of creating a binary tree
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Create an instance of the Solution class
    Solution solution;

    // Perform zigzag level order traversal
    vector<vector<int>> zigzagTraversal = solution.zigzagLevelOrder(root);

    // Print the result
    cout << "Zigzag level order traversal:" << endl;
    printVector(zigzagTraversal);

    return 0;
}
