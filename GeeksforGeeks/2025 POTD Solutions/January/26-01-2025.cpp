/*
Problem of the Day: Remove loop in Linked List
Problem Description: https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
*/

class Solution {
  public:
    void removeLoop(Node* head) {
        if (head == nullptr || head->next == nullptr)
            return;

        Node *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }

        if (slow == fast) {
            slow = head;
            if (slow != fast) {
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
                fast->next = nullptr;
            } else {
                while (fast->next != slow) {
                    fast = fast->next;
                }
                fast->next = nullptr;
            }
        }
    }
};
