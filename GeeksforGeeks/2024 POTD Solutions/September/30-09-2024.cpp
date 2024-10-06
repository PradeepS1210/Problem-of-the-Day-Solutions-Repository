/*
Problem of the Day: Merge two BST ‘s
Problem Description: https://medium.com/@pradeepsooryavanshee1210/merge-two-bst-s-geeksforgeeks-solution-e2caa94f1697
*/

class Solution {
public:
    void inorderTraversal(Node* root, vector<int>& result) {
        if (!root) return;
        inorderTraversal(root->left, result);
        result.push_back(root->data);
        inorderTraversal(root->right, result);
    }
    
    vector<int> mergeSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
        vector<int> merged;
        int i = 0, j = 0;
        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] < arr2[j]) {
                merged.push_back(arr1[i++]);
            } else {
                merged.push_back(arr2[j++]);
            }
        }
        while (i < arr1.size()) merged.push_back(arr1[i++]);
        while (j < arr2.size()) merged.push_back(arr2[j++]);
        return merged;
    }
    
    vector<int> merge(Node* root1, Node* root2) {
        vector<int> bst1Elements, bst2Elements;
        
        inorderTraversal(root1, bst1Elements);
        inorderTraversal(root2, bst2Elements);
        
        return mergeSortedArrays(bst1Elements, bst2Elements);
    }
};