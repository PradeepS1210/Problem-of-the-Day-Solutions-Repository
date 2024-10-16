/*
Problem of the Day: Remove multiple Occurrence
Problem Description: https://medium.com/@pradeepsooryavanshee1210/remove-multiple-occurrence-unstop-solution-405977b9b90b
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeDuplicates(ListNode* head) {
    if (!head) return nullptr;

    ListNode* current = head;
    ListNode* uniqueHead = nullptr;
    ListNode* uniqueTail = nullptr;

    while (current) {
        if (!uniqueHead || uniqueTail->val != current->val) {
            ListNode* newNode = new ListNode(current->val);
            if (!uniqueHead) {
                uniqueHead = newNode;
                uniqueTail = newNode;
            } else {
                uniqueTail->next = newNode;
                uniqueTail = newNode;
            }
        }
        current = current->next;
    }

    return uniqueHead;
}

ListNode* createLinkedList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (int i = 1; i < arr.size(); i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val;
        if (current->next) cout << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    ListNode* head = createLinkedList(arr);
    
    ListNode* updatedList = mergeDuplicates(head);
    
    printLinkedList(updatedList);
    
    return 0;
}