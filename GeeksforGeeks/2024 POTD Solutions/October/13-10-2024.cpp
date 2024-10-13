/*
Problem of the Day: Delete Alternate Nodes
Problem Description: https://medium.com/@pradeepsooryavanshee1210/delete-alternate-nodes-geeksforgeeks-solution-c7a7b5d059c4
*/

class Solution {
  public:
    void deleteAlt(struct Node *head) {
        if (head == NULL) return;
        
        Node* current = head;
        
        while (current != NULL && current->next != NULL) {
            Node* temp = current->next;
            current->next = current->next->next;
            
            delete temp;
            
            current = current->next;
        }
    }
};