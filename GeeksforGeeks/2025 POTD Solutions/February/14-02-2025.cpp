/*
Problem of the Day: Fixing Two nodes of a BST
Problem Description: https://www.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1
*/

class Solution {
  private:
    Node* first;
    Node* second;
    Node* prev;
  
    void inorder(Node* node) {
        if (!node) return;
        
        inorder(node->left);
        
        if (prev && prev->data > node->data) {
            if (!first) {
                first = prev;
            }
            second = node;
        }
        
        prev = node;
        inorder(node->right);
    }
  
  public:
    void correctBST(Node* root) {
        first = nullptr;
        second = nullptr;
        prev = nullptr;
        
        inorder(root);
        
        if (first && second) {
            int temp = first->data;
            first->data = second->data;
            second->data = temp;
        }
    }
};
