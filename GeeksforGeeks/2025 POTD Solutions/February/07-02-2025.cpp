/*
Problem of the Day: Inorder Traversal
Problem Description: https://www.geeksforgeeks.org/problems/inorder-traversal/1
*/

class Solution {
  public:
    void inOrderHelper(Node* root, vector<int>& result) {
        if (root != NULL) {
            inOrderHelper(root->left, result);
            result.push_back(root->data);
            inOrderHelper(root->right, result);
        }
    }

    vector<int> inOrder(Node* root) {
        vector<int> result;
        inOrderHelper(root, result);
        return result;
    }
};
