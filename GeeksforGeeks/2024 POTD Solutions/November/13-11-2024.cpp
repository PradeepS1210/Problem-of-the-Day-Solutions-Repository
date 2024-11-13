/*
Problem of the Day: Intersection Point in Y Shaped Linked Lists
Problem Description: https://medium.com/@pradeepsooryavanshee1210/intersection-point-in-y-shaped-linked-lists-geeksforgeeks-solution-4e303303b7f0
*/

class Solution {
  public:
    int intersectPoint(Node* head1, Node* head2) {
        Node* ptr1 = head1;
        Node* ptr2 = head2;

        while (ptr1 != ptr2) {
            ptr1 = (ptr1 == NULL) ? head2 : ptr1->next;
            ptr2 = (ptr2 == NULL) ? head1 : ptr2->next;
        }

        return (ptr1 != NULL) ? ptr1->data : -1;
    }
};
