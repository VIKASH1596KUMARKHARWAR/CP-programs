// create node until user enter -1,ternmimate for this

#include <iostream>
using namespace std;
#include "NodeClass.cpp"

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

void print(Node *head)
{
    Node *temp = head; // Create a temporary pointer to traverse the list

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = takeInput_Better();
    print(head);
    /*   int len = length(head);
       cout << endl;
       cout << " length of list is " << len;*/
}