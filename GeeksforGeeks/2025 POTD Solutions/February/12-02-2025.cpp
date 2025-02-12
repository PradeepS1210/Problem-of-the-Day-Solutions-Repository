/*
Problem of the Day: k-th Smallest in BST
Problem Description: https://www.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1
*/

class Solution {
  public:
    void inOrderTraversal(Node* root, vector<int>& elements) {
        if (root == nullptr) {
            return;
        }
        inOrderTraversal(root->left, elements);
        elements.push_back(root->data);
        inOrderTraversal(root->right, elements);
    }
    
    int kthSmallest(Node* root, int k) {
        vector<int> elements;
        inOrderTraversal(root, elements);
        
        if (k > 0 && k <= elements.size()) {
            return elements[k - 1];
        }
        
        return -1;
    }
};
