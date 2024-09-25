/*
Asked in Accolite, Amazon, Microsoft, Snapdeal, MakeMyTrip, Adobe, Yodlee Infotech, KLA Tencor, Kritikal Solutions
Problem of the Day: Palindrome Linked List
Problem Description: https://medium.com/@pradeepsooryavanshee1210/palindrome-linked-list-geeksforgeeks-solution-6fc6ad59b145
*/

class Solution
{
private:
    Node *reverseList(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        while (curr != NULL)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    bool isPalindrome(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }

        Node *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *secondHalf = reverseList(slow);

        Node *firstHalf = head;
        Node *secondHalfCopy = secondHalf;
        bool isPalindrome = true;
        while (secondHalf != NULL)
        {
            if (firstHalf->data != secondHalf->data)
            {
                isPalindrome = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        reverseList(secondHalfCopy);

        return isPalindrome;
    }
};