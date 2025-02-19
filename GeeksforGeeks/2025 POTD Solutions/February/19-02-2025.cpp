/*
Problem of the Day: Merge K sorted linked lists
Problem Description: https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
*/

class Solution {
public:
    struct CompareNode {
        bool operator()(Node* const& p1, Node* const& p2) {
            return p1->data > p2->data;
        }
    };

    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*, vector<Node*>, CompareNode> minHeap;
        for (Node* list : arr) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }
        Node* dummy = new Node(0);
        Node* current = dummy;
        while (!minHeap.empty()) {
            Node* minNode = minHeap.top();
            minHeap.pop();
            current->next = minNode;
            current = current->next;
            if (minNode->next != nullptr) {
                minHeap.push(minNode->next);
            }
        }
        Node* head = dummy->next;
        delete dummy;
        return head;
    }
};
