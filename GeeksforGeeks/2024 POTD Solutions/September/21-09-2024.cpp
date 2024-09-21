/*
Problem of the Day: Clone a linked list with next and random pointer
Problem Description: https://medium.com/@pradeepsooryavanshee1210/clone-a-linked-list-with-next-and-random-pointer-geeksforgeeks-solution-ffdd3c72abf5
*/

class Solution
{
public:
    Node *copyList(Node *head)
    {
        if (!head)
            return nullptr;

        Node *curr = head;
        while (curr)
        {
            Node *newNode = new Node(curr->data);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        curr = head;
        while (curr)
        {
            if (curr->random)
            {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        curr = head;
        Node *copyHead = head->next;
        Node *copyCurr = copyHead;
        while (curr)
        {
            curr->next = curr->next->next;
            if (copyCurr->next)
            {
                copyCurr->next = copyCurr->next->next;
            }
            curr = curr->next;
            copyCurr = copyCurr->next;
        }

        return copyHead;
    }
};