/*
Problem of the Day: Middle of a Linked List
Problem Description: https://medium.com/@pradeepsooryavanshee1210/middle-of-a-linked-list-geeksforgeeks-solution-1e7292d90810
*/

class Solution
{
public:
    int getMiddle(Node *head)
    {
        if (head == nullptr)
        {
            return -1;
        }

        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }
};