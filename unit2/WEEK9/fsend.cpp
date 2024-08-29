#include <climits>
int Floor(BinaryTreeNode<int> *node, int input)
{
    // we need to find the largest node in the tree that is less than or equal to input

    if (node == nullptr)
    {
        return INT_MIN; // If tree is empty, return INT_MIN
    }

    int floorValue = INT_MIN;
    BinaryTreeNode<int> *current = node;

    while (current != nullptr)
    {
        if (current->data == input)
        {
            return current->data; // Found exact match, return input itself as floor
        }
        else if (current->data > input)
        {
            current = current->left; // Move to the left subtree
        }
        else
        {
            // current->data <= input

            floorValue = current->data; // Update floorValue to current node's data
            current = current->right;   // Move to the right subtree
        }
    }

    return floorValue;
}