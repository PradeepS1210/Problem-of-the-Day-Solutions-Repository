/*
Problem of the Day: Is Linked List Length Even?
Problem Description: https://medium.com/@pradeepsooryavanshee1210/is-linked-list-length-even-geeksforgeeks-solution-c3e3a1d754c7
*/

class Solution {
  public:
    bool isLengthEven(struct Node **head) {
        int count = 0;
        
        if (*head == NULL) {
            return true;
        }

        struct Node* current = *head; 
        while (current != NULL) {
            count++;
            current = current->next;
        }

        return (count % 2 == 0);
    }
};