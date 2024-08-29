// create node until user enter -1,ternmimate for this

#include <iostream>
using namespace std;
#include "Nodec.cpp"

Node *takeInput_Better()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1)
    {
        Node *newNode = new Node(data);

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

Node *insertNodeAtInd(Node *head, int i, int data)
{
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;

    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        Node *a = temp->next;
        temp->next = newNode;
        newNode->next = a;
    }
    return head;
}

Node *deleteNode(Node *head, int pos)
{
    if (head == NULL)
    {
        return head;
    }
    if (pos == 0)
    {
        return head->next;
    }

    Node *curr = head;
    int currPos = 0;

    while (curr != NULL && currPos < pos - 1)
    {
        ++currPos;
        curr = curr->next;
    }
    if (curr == NULL || curr->next == NULL)
    {
        return head;
    }
    curr->next = curr->next->next;
    return head;
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
    int i, j, data;
    cin >> i >> data;
    head = insertNodeAtInd(head, i, data);
    print(head);
    cin >> j;
    head = deleteNode(head, j);
    print(head);
}