/*
Problem of the Day: Occurence of an integer in a Linked List
Problem  Description: https://medium.com/@pradeepsooryavanshee1210/occurence-of-an-integer-in-a-linked-list-geeksforgeeks-solution-714962487699
*/

class Solution {
  public:
    int count(struct Node* head, int key) {
        int count = 0;
        struct Node* current = head;
        
        while (current != NULL) {
            if (current->data == key) {
                count++;
            }
            current = current->next;
        }
        
        return count;
    }
};
