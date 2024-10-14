/*
Problem of the Day: Count Linked List Nodes 
Problem Description: https://medium.com/@pradeepsooryavanshee1210/count-linked-list-nodes-geeksforgeeks-solution-5cdde5c96c76
*/

class Solution {
  public:
    int getCount(struct Node* head) {
        int count = 0;
        
        struct Node* current = head;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        
        return count;
    }
};