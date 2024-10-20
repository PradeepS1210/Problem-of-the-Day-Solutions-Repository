/*
Problem of the Day: Range Square
Problem Description: https://medium.com/@pradeepsooryavanshee1210/range-square-unstop-solution-6541fd8783f5
*/

#include <iostream>
#include <cmath>
#include <unordered_set>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insert(Node*& head, int value) {
    if (!head) {
        head = new Node(value);
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new Node(value);
    }
}

bool isPerfectSquare(int num) {
    int root = sqrt(num);
    return root * root == num;
}

int main() {
    int N1, N2;
    cin >> N1 >> N2;
    
    int N;
    cin >> N;
    
    Node* head = nullptr;
    
    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        insert(head, value);
    }

    unordered_set<int> perfectSquares;

    for (int i = N1; i <= N2; i++) {
        perfectSquares.insert(i * i);
    }

    Node* current = head;
    while (current) {
        if (perfectSquares.find(current->data) != perfectSquares.end()) {
            cout << 1 << endl;
            return 0;
        }
        current = current->next;
    }

    cout << 0 << endl;

    return 0;
}
