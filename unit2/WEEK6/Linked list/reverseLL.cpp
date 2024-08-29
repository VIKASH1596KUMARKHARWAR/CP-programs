Node *reverseLL_Recursively(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *smallAns = reverseLL_Recursively(head->next);

    Node *tail = head->next; // address of 2nd element
    tail->next = head;       //(n-1)th ele  ke next meih head(meas first ele);
    head->next = NULL;
    return smallAns;
}