/*
Problem of the Day: Deletion and Reverse in Circular Linked List
Problem Description: https://medium.com/@pradeepsooryavanshee1210/deletion-and-reverse-in-circular-linked-list-geeksforgeeks-solution-7c1b9936673c
*/

class Solution {
public:
    Node* reverse(Node* head) {
        if (!head || head->next == head) {
            return head;
        }

        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        Node* tail = head;

        do {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != head);

        tail->next = prev;

        return prev;
    }

    Node* deleteNode(Node* head, int key) {
        if (!head) return nullptr;

        Node* current = head;
        Node* prev = nullptr;

        if (head->data == key) {
            if (head->next == head) {
                delete head;
                return nullptr;
            }

            Node* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }

            tail->next = head->next;
            Node* newHead = head->next;
            delete head;
            return newHead;
        }

        do {
            prev = current;
            current = current->next;
        } while (current != head && current->data != key);

        if (current->data == key) {
            prev->next = current->next;
            delete current;
        }

        return head;
    }
};