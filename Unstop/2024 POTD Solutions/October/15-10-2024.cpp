/*
Problem of the Day: Target Value
Problem Description: https://medium.com/@pradeepsooryavanshee1210/target-value-unstop-solution-abffe26a3fde
*/

#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int countPairs(Node* head, int target) {
    unordered_map<int, int> numCount;
    int pairCount = 0;

    Node* current = head;
    while (current != nullptr) {
        int complement = target - current->data;
        if (numCount.find(complement) != numCount.end()) {
            pairCount += numCount[complement];
        }
        numCount[current->data]++;
        current = current->next;
    }
    
    return pairCount;
}

Node* createLinkedList(int arr[], int size) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < size; i++) {
        Node* newNode = new Node(arr[i]);
        if (head == nullptr) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    
    return head;
}

int main() {
    int N;
    cin >> N;
    int* values = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> values[i];
    }

    int target;
    cin >> target;

    Node* head = createLinkedList(values, N);

    int result = countPairs(head, target);

    cout << result << endl;

    delete[] values;

    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}