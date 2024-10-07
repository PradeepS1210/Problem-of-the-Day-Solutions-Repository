/*
Asked in Accolite, Amazon, GE
Problem of the Day: XOR Linked List
Problem Description: https://medium.com/@pradeepsooryavanshee1210/xor-linked-list-geeksforgeeks-solution-e6612553f407
*/

struct Node* insert(struct Node *head, int data) {
    Node* newNode = new Node(data);

    newNode->npx = XOR(NULL, head);

    if (head != NULL) {
        Node* nextNode = XOR(NULL, head->npx);
        head->npx = XOR(newNode, nextNode);
    }

    return newNode;
}

vector<int> getList(struct Node *head) {
    vector<int> result;
    Node* curr = head;
    Node* prev = NULL;
    Node* next;

    while (curr != NULL) {
        result.push_back(curr->data);

        next = XOR(prev, curr->npx);

        prev = curr;
        curr = next;
    }

    return result;
}