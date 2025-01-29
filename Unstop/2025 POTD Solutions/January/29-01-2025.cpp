/*
Problem of the Day: Consecutive Longest arithmetic Progression
Problem Description: https://unstop.com/code/practice/307299
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

int longestAP(Node* head) {
    if (!head) return 0;

    Node* current = head;
    vector<int> values;

    while (current) {
        values.push_back(current->val);
        current = current->next;
    }

    int n = values.size();
    if (n <= 1) return n;

    int longestLength = 1;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int d = values[j] - values[i];
            int len = 2;

            int prev = values[j];
            for (int k = j + 1; k < n; ++k) {
                if (values[k] == prev + d) {
                    len++;
                    prev = values[k];
                }
            }

            longestLength = max(longestLength, len);
        }
    }

    return longestLength;
}

Node* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    Node* head = new Node(values[0]);
    Node* current = head;
    for (int i = 1; i < values.size(); ++i) {
        current->next = new Node(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int n;
    cin >> n;

    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    Node* head = createLinkedList(values);
    cout << longestAP(head) << endl;

    return 0;
}
