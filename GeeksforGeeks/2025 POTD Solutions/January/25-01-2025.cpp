/*
Problem of the Day: Find the first node of loop in linked list
Problem Description: https://www.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1
*/

class Solution {
  public:
    Node* findFirstNode(Node* head) {
        if (head == nullptr || head->next == nullptr) return nullptr;

        Node *slow = head, *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }

        if (fast == nullptr || fast->next == nullptr) return nullptr;
        
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};
