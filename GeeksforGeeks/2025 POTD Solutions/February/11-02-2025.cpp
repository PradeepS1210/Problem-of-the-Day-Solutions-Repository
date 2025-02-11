/*
Examples:
----------
Input: root = [2, 1, 3, N, N, N, 5]
Output: true 
Explanation: The left subtree of every node contains smaller keys and right subtree of every node contains greater keys. Hence, the tree is a BST.

Input: root = [2, N, 7, N, 6, N, 9] 
Output: false 
Explanation: Since the node to the right of node with key 7 has lesser key value, hence it is not a valid BST.

Input: root = [10, 5, 20, N, N, 9, 25]
Output: false
Explanation: The node with key 9 present in the right subtree has lesser key value than root node.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    bool isBST(Node* root) {
        return isBSTUtil(root, LONG_MIN, LONG_MAX);
    }

  private:
    bool isBSTUtil(Node* node, long long minVal, long long maxVal) {
        if (node == nullptr) {
            return true;
        }

        if (node->data <= minVal || node->data >= maxVal) {
            return false;
        }

        return isBSTUtil(node->left, minVal, node->data) && isBSTUtil(node->right, node->data, maxVal);
    }
};

Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

Node* createBinaryTree() {
    int n, data;
    cout << "Enter the number of nodes: ";
    cin >> n;
    Node* root = nullptr;
    cout << "Enter the node values:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> data;
        root = insertNode(root, data);
    }
    return root;
}

int main() {
    Node* root = createBinaryTree();
    Solution sol;
    if (sol.isBST(root)) {
        cout << "The binary tree is a BST" << endl;
    } else {
        cout << "The binary tree is not a BST" << endl;
    }
    return 0;
}
