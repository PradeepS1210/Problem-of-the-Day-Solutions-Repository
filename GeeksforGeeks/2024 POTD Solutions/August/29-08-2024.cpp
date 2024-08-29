/*
Asked in Amazon, Adobe, Qualcomm
Problem of the Day: Find length of Loop
Problem Description: https://medium.com/@pradeepsooryavanshee1210/find-length-of-loop-geeksforgeeks-solution-9110fe4c69a1
*/

class Solution
{
public:
    int countNodesinLoop(struct Node *head)
    {
        if (head == NULL || head->next == NULL)
            return 0;

        struct Node *slow = head, *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                int loopLength = 1;
                struct Node *temp = slow;

                while (temp->next != slow)
                {
                    loopLength++;
                    temp = temp->next;
                }
                return loopLength;
            }
        }

        return 0;
    }
};