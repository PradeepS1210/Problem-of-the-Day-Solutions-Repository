/*
Problem of the Day: Linked List Group Reverse
Problem Description: https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        if (!head || k <= 1) return head;
        
        Node *current = head;
        Node *prevTail = NULL;
        Node *newHead = NULL;
        
        while (current) {
            Node *groupHead = NULL;
            Node *groupTail = current;
            Node *prev = NULL;
            int count = 0;
            
            while (current && count < k) {
                Node *next = current->next;
                current->next = prev;
                prev = current;
                current = next;
                count++;
            }
            
            if (!newHead) {
                newHead = prev;
            }
            
            if (prevTail) {
                prevTail->next = prev;
            }
            
            prevTail = groupTail;
        }
        
        if (prevTail) {
            prevTail->next = NULL;
        }
        
        return newHead;
    }
};
