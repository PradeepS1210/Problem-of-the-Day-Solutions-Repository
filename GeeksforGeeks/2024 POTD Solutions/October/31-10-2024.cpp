/*
Problem of the Day: Insert in Sorted way in a Sorted DLL
Problem Description: https://medium.com/@pradeepsooryavanshee1210/insert-in-sorted-way-in-a-sorted-dll-geeksforgeeks-solution-980025394723
*/

class Solution {
public:
    Node* sortedInsert(Node* head, int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        
        if (!head) return newNode;
        
        if (x < head->data) {
            newNode->next = head;
            head->prev = newNode;
            return newNode;
        }
        
        Node* current = head;
        while (current->next && current->next->data < x) {
            current = current->next;
        }
        
        newNode->next = current->next;
        if (current->next) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
        
        return head;
    }
};
