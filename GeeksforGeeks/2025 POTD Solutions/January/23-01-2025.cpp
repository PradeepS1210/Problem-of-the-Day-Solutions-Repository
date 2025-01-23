/*
Problem of the Day: Clone List with Next and Random
Problem Description: https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
*/

/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        if (!head) return NULL;

        Node *curr = head;
        while (curr) {
            Node *newNode = new Node(curr->data);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        Node *original = head;
        Node *copy = head->next;
        Node *copyHead = copy;

        while (original && copy) {
            original->next = original->next->next;
            if (copy->next) {
                copy->next = copy->next->next;
            }
            original = original->next;
            copy = copy->next;
        }

        return copyHead;
    }
};
