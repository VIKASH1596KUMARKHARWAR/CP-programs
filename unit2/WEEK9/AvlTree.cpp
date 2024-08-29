#include <iostream>
#include <algorithm>
using namespace std;

// Structure of a node in AVL tree
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height; // Height of the subtree rooted at this node

    // Constructor
    Node(int value)
    {
        data = value;
        left = right = nullptr;
        height = 1; // New node is initially added at leaf level, so height is 1
    }
};

// Function to get the height of a node
int getHeight(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->height;
}

// Function to get the balance factor of a node
int getBalance(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Function to right rotate subtree rooted with y
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    // Return new root
    return x;
}

// Function to left rotate subtree rooted with x
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    // Return new root
    return y;
}

// Function to insert a node into the AVL tree
Node *insert(Node *root, int value)
{
    // Perform the normal BST insertion
    if (root == nullptr)
    {
        return new Node(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else
    { // Duplicate keys are not allowed in AVL tree
        return root;
    }

    // Update height of this ancestor node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are four cases

    // Left Left Case
    if (balance > 1 && value < root->left->data)
    {
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && value > root->right->data)
    {
        return leftRotate(root);
    }

    // Left Right Case
    if (balance > 1 && value > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && value < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // If the node is already balanced
    return root;
}

// Function to find the node with minimum key value in a given AVL tree
Node *minValueNode(Node *node)
{
    Node *current = node;

    // Loop down to find the leftmost leaf
    while (current && current->left != nullptr)
    {
        current = current->left;
    }

    return current;
}

// Function to delete a node from the AVL tree
Node *deleteNode(Node *root, int value)
{
    // Perform standard BST delete
    if (root == nullptr)
    {
        return root;
    }

    // If the key to be deleted is smaller than the root's key, then it lies in the left subtree
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    // If the key to be deleted is greater than the root's key, then it lies in the right subtree
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    // If key is the same as root's key, then this is the node to be deleted
    else
    {
        // Node with only one child or no child
        if (root->left == nullptr || root->right == nullptr)
        {
            Node *temp = root->left ? root->left : root->right;

            // No child case
            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else
            {                  // One child case
                *root = *temp; // Copy the contents of the non-empty child
            }
            delete temp;
        }
        else
        {
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node *temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }

    // If the tree had only one node, then return
    if (root == nullptr)
    {
        return root;
    }

    // Update height of the current node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Get the balance factor of this node to check whether this node became unbalanced
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are four cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
    {
        return rightRotate(root);
    }

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
    {
        return leftRotate(root);
    }

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // If the node is already balanced
    return root;
}

// Function to search for a node with given value in the AVL tree
Node *search(Node *root, int value)
{
    // Base cases: root is null or key is present at root
    if (root == nullptr || root->data == value)
    {
        return root;
    }

    // Key is greater than root's key
    if (root->data < value)
    {
        return search(root->right, value);
    }

    // Key is smaller than root's key
    return search(root->left, value);
}

// Function to print in-order traversal of the AVL tree
void inOrder(Node *root)
{
    if (root != nullptr)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// Driver program to test above functions
int main()
{
    Node *root = nullptr;

    // Insert elements into the AVL tree
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    // Print in-order traversal of the AVL tree
    cout << "In-order traversal of the AVL tree after insertion: ";
    inOrder(root);
    cout << endl;

    // Search for a value in the AVL tree
    int searchValue = 10;
    Node *foundNode = search(root, searchValue);
    if (foundNode)
    {
        cout << "Node with value " << searchValue << " found in the AVL tree." << endl;
    }
    else
    {
        cout << "Node with value " << searchValue << " not found in the AVL tree." << endl;
    }

    // Delete elements from the AVL tree
    int deleteValue = 10;
    root = deleteNode(root, deleteValue);
    cout << "In-order traversal of the AVL tree after deletion of node with value " << deleteValue << ": ";
    inOrder(root);
    cout << endl;

    return 0;
}
