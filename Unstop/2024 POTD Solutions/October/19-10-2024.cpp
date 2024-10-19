/*
Problem of the Day: Common Node Data
Problem Description: https://medium.com/@pradeepsooryavanshee1210/common-node-data-unstop-solution-362392f6b2b9
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    void push(int data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }
};

int get_length(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

Node* align_lists(Node* head1, Node* head2, int diff) {
    for (int i = 0; i < diff; i++) {
        head1 = head1->next;
    }
    return head1;
}

int find_common_node(Node* head1, Node* head2) {
    int len1 = get_length(head1);
    int len2 = get_length(head2);

    if (len1 > len2) {
        head1 = align_lists(head1, head2, len1 - len2);
    } else {
        head2 = align_lists(head2, head1, len2 - len1);
    }

    while (head1 && head2) {
        if (head1->data == head2->data) {
            Node* temp1 = head1;
            Node* temp2 = head2;
            while (temp1 && temp2 && temp1->data == temp2->data) {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            if (temp1 == nullptr && temp2 == nullptr) {
                return head1->data;
            }
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return -1;
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    LinkedList ll1;
    LinkedList ll2;

    for (int i = 0; i < n1; i++) {
        int value;
        cin >> value;
        ll1.push(value);
    }

    for (int i = 0; i < n2; i++) {
        int value;
        cin >> value;
        ll2.push(value);
    }

    int result = find_common_node(ll1.head, ll2.head);
    cout << result << endl;

    return 0;
}
