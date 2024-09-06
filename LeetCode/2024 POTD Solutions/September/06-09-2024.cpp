/*
Problem of the Day: 3217. Delete Nodes From Linked List Present in Array
Problem Description: https://medium.com/@pradeepsooryavanshee1210/3217-delete-nodes-from-linked-list-present-in-array-leetcode-solution-63d6147f0581
*/

class Solution
{
public:
    ListNode *modifiedList(std::vector<int> &nums, ListNode *head)
    {
        std::unordered_set<int> to_remove(nums.begin(), nums.end());

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *prev = dummy;
        ListNode *current = head;

        while (current != nullptr)
        {
            if (to_remove.find(current->val) != to_remove.end())
            {
                prev->next = current->next;
            }
            else
            {
                prev = current;
            }
            current = current->next;
        }

        return dummy->next;
    }
};