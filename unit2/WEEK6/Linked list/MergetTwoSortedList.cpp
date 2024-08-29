Node *mrgetTwoSortedLinkedList(Node *head1, Node *head2)
{
    if (head1 == nullptr)
    {
        return head2;
    }
    if (head2 == nullptr)
    {
        return head1;
    }

    Node *newhead = nullptr;
    Node *newtail = nullptr;

    // Initialize newhead and newtail to the smaller head node
    if (head1->data < head2->data)
    {
        newhead = newtail = head1;
        head1 = head1->next;
    }
    else
    {
        newhead = newtail = head2;
        head2 = head2->next;
    }

    // Merge remaining nodes
    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->data < head2->data)
        {
            newtail->next = head1;
            head1 = head1->next;
        }
        else
        {
            newtail->next = head2;
            head2 = head2->next;
        }
        newtail = newtail->next;
    }

    // Append remaining nodes of head1 or head2
    if (head1 != nullptr)
    {
        newtail->next = head1;
    }
    if (head2 != nullptr)
    {
        newtail->next = head2;
    }

    return newhead;
}
