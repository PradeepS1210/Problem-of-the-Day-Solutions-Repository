/*
Problem of the Day: Lowest Common Ancestor in a BST
Problem Description: https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1
*/

class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if (root == NULL) return NULL;

        if (root->data > n1->data && root->data > n2->data)
            return LCA(root->left, n1, n2);

        if (root->data < n1->data && root->data < n2->data)
            return LCA(root->right, n1, n2);

        return root;
    }
};
