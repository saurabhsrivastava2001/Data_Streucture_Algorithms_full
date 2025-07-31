

Node* reverseList(Node* head) {
    // Base case: empty list or single node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Recursive case: reverse the rest
    Node* newHead = reverseList(head->next);

    // Reverse the pointers
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}
