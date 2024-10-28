/*
Problem of the Day: Mountain Valley
Problem Description: https://medium.com/@pradeepsooryavanshee1210/mountain-valley-unstop-solution-4b2bb5bcb81a
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int countPeakNodes(Node* head) {
    if (!head || !head->next || !head->next->next) return 0;

    int peakCount = 0;
    Node* prev = head;
    Node* curr = head->next;
    Node* next = curr->next;

    while (next) {
        if (curr->data > prev->data && curr->data > next->data) {
            peakCount++;
        }
        prev = curr;
        curr = next;
        next = next->next;
    }
    return peakCount;
}

void appendNode(Node*& head, int val) {
    if (!head) {
        head = new Node(val);
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new Node(val);
    }
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        appendNode(head, value);
    }

    int result = countPeakNodes(head);
    cout << result << endl;

    return 0;
}
