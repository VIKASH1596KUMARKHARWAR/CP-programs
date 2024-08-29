// spme opertation like length calclate ,inssert at ith positon
#include <iostream>
using namespace std;
#include "NodeClas.cpp"

Node *takeInput_Better()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1)
    {
        Node *newNode = new Node(data);
        // newNode in stack having address of newly dynamically created node ===>its pointer

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
            // or tail = newNode;
        }
        cin >> data;
    }
    return head;
}

int length(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
    // Write your code here
}

int length_recursively(Node *head)
{
    // Base case: If head is nullptr, return 0
    if (head == nullptr)
    {
        return 0;
    }
    // Recursive case: Count the length of the rest of the list and add 1 for the current node
    return 1 + length(head->next);
}

void printIthNode(Node *head, int i)
{
    // Write your code here
    int index = 0;
    Node *temp = head;
    while (temp != NULL && index < i)
    {
        index++;
        temp = temp->next;
    }
    if (temp == NULL)
    {
    }
    else
    {
        cout << temp->data;
    }
}
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    Node *head = takeInput_Better();
    print(head);
    int len = length(head);
    cout << endl;
    cout << " length of list is " << len << endl;
    cout << "at index 2 element  is " << printIthNode(head, 2);
}