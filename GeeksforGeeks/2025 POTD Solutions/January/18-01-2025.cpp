/*
Problem of the Day: Reverse a linked list
Problem Description: https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1
*/

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        Node* prev = NULL;
        Node* curr = head;

        while (curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
