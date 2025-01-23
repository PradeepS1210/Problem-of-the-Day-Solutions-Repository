/*
Problem of the Day: Form Double–Linked List From ArrayList Node
Problem Description: https://unstop.com/code/practice/297466
*/

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void printDoublyLinkedList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data;
        if (curr->next != NULL) cout << " <---> ";
        curr = curr->next;
    }
    cout << " <---> null" << endl;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> arr(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
        }
    }

    vector<Node*> nodes;

    for (int i = 0; i < N; ++i) {
        Node* head = new Node(arr[i][0]);
        Node* current = head;
        for (int j = 1; j < M; ++j) {
            Node* newNode = new Node(arr[i][j]);
            current->next = newNode;
            newNode->prev = current;
            current = newNode;
        }
        nodes.push_back(head);
    }

    Node* dummyHead = new Node(0);
    Node* last = dummyHead;

    for (int i = 0; i < nodes.size(); i += 2) {
        if (nodes[i] != NULL) {
            last->next = nodes[i];
            nodes[i]->prev = last;
            while (last->next != NULL) {
                last = last->next;
            }
        }
    }

    for (int i = 1; i < nodes.size(); i += 2) {
        if (nodes[i] != NULL) {
            last->next = nodes[i];
            nodes[i]->prev = last;
            while (last->next != NULL) {
                last = last->next;
            }
        }
    }

    Node* finalListHead = dummyHead->next;
    if (finalListHead != NULL) {
        finalListHead->prev = NULL;
    }
    printDoublyLinkedList(finalListHead);

    return 0;
}
