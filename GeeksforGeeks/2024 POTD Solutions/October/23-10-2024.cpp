/*
Problem of the Day: Find the Sum of Last N nodes of the Linked List
Problem Description: https://medium.com/@pradeepsooryavanshee1210/find-the-sum-of-last-n-nodes-of-the-linked-list-geeksforgeeks-solution-8bd7b822dbbb
*/

class Solution {
  public:
    /*Structure of the node of the linled list is as

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    // your task is to complete this function
    // function should return sum of last n nodes
    int sumOfLastN_Nodes(struct Node* head, int n) {
        struct Node* fast = head;
        struct Node* slow = head;
        
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }
        
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        int sum = 0;
        while (slow != NULL) {
            sum += slow->data;
            slow = slow->next;
        }
        
        return sum;
    }
};
