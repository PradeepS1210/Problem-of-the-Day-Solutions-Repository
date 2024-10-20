/*
Problem of the Day: Sort a k sorted doubly linked list
Problem Description: https://medium.com/@pradeepsooryavanshee1210/sort-a-k-sorted-doubly-linked-list-geeksforgeeks-solution-66d4b902972f
*/

class Solution {
  public:

    DLLNode* sortAKSortedDLL(DLLNode* head, int k) {
        if (head == nullptr) return nullptr;

        priority_queue<DLLNode*, vector<DLLNode*>, greaterCompare> minHeap;

        DLLNode* newHead = nullptr;
        DLLNode* last = nullptr;

        DLLNode* curr = head;
        for (int i = 0; curr != nullptr && i <= k; i++) {
            minHeap.push(curr);
            curr = curr->next;
        }

        while (!minHeap.empty()) {
            DLLNode* minNode = minHeap.top();
            minHeap.pop();

            if (newHead == nullptr) {
                newHead = minNode;
                newHead->prev = nullptr;
                last = newHead;
            } else {
                last->next = minNode;
                minNode->prev = last;
                last = minNode;
            }

            if (curr != nullptr) {
                minHeap.push(curr);
                curr = curr->next;
            }
        }

        last->next = nullptr;
        return newHead;
    }

    struct greaterCompare {
        bool operator()(DLLNode* a, DLLNode* b) {
            return a->data > b->data;
        }
    };
};
