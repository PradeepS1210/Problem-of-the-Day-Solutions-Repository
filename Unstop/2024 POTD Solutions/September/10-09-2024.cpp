/*
Asked in OYO Rooms, Infosys, TCS
Problem of the Day: Swapping Linked List Node
Problem Description: https://medium.com/@pradeepsooryavanshee1210/swapping-linked-list-node-unstop-solution-32a787f04d8d
*/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *swapNodes(ListNode *head, int k)
{
    ListNode *first = head, *second = head, *kthFromBegin = nullptr;
    int n = 0;

    while (first != nullptr)
    {
        n++;
        if (n == k)
        {
            kthFromBegin = first;
        }
        first = first->next;
    }

    int kthFromEndIndex = n - k + 1;

    first = head;

    for (int i = 1; i < kthFromEndIndex; i++)
    {
        first = first->next;
    }

    int temp = kthFromBegin->val;
    kthFromBegin->val = first->val;
    first->val = temp;

    return head;
}

ListNode *createList(int arr[], int n)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;
    for (int i = 1; i < n; i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    ListNode *head = createList(arr, n);

    head = swapNodes(head, k);

    printList(head);

    return 0;
}