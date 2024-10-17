/*
Problem of the Day: Split Linked List Alternatingly
Problem Description: https://medium.com/@pradeepsooryavanshee1210/split-linked-list-alternatingly-geeksforgeeks-solution-745684c6333e
*/

class Solution {
  public:
    vector<Node*> alternatingSplitList(struct Node* head) {
        Node* a = NULL;
        Node* b = NULL;
        Node* aTail = NULL;
        Node* bTail = NULL;

        bool alternate = true;

        Node* current = head;
        while (current != NULL) {
            if (alternate) {
                if (a == NULL) {
                    a = current;
                    aTail = current;
                } else {
                    aTail->next = current;
                    aTail = aTail->next;
                }
            } else {
                if (b == NULL) {
                    b = current;
                    bTail = current;
                } else {
                    bTail->next = current;
                    bTail = bTail->next;
                }
            }

            current = current->next;

            alternate = !alternate;
        }

        if (aTail != NULL) aTail->next = NULL;
        if (bTail != NULL) bTail->next = NULL;

        return {a, b};
    }
};