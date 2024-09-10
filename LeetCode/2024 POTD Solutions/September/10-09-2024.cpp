/*
Problem of the Day: 2807. Insert Greatest Common Divisors in Linked List
Problem Description: https://medium.com/@pradeepsooryavanshee1210/2807-insert-greatest-common-divisors-in-linked-list-leetcode-solution-efcba4e8e125
*/

class Solution
{
public:
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *current = head;

        while (current && current->next)
        {
            int gcdValue = std::__gcd(current->val, current->next->val);

            ListNode *gcdNode = new ListNode(gcdValue);

            gcdNode->next = current->next;
            current->next = gcdNode;

            current = gcdNode->next;
        }

        return head;
    }
};