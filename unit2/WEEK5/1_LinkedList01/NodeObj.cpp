#include <iostream>
using namespace std;
#include "1_Node.cpp"

int main()
{

    // statically
    Node n1(1);
    Node *head = &n1;

    Node n2(2);

    n1.next = &n2;

    // cout << n1.data << " " << n2.data << endl;

    cout << head->data << endl;
    cout << head->next->data;

    // dynamically
    Node *n3 = new Node(10);
    Node *head = n3;

    Node *n4 = new Node(20);

    n3->next = n4;
}