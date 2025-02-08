/*
Problem of the Day: Tree Boundary Traversal
Problem Description: https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
*/

class Solution {
  public:
    void getLeftBoundary(Node* root, vector<int>& res) {
        Node* curr = root->left;
        while (curr) {
            if (!(curr->left == NULL && curr->right == NULL)) {
                res.push_back(curr->data);
            }
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    void getLeafNodes(Node* root, vector<int>& res) {
        if (!root) return;
        if (root->left == NULL && root->right == NULL) {
            res.push_back(root->data);
            return;
        }
        getLeafNodes(root->left, res);
        getLeafNodes(root->right, res);
    }

    void getRightBoundary(Node* root, vector<int>& res) {
        vector<int> temp;
        Node* curr = root->right;
        while (curr) {
            if (!(curr->left == NULL && curr->right == NULL)) {
                temp.push_back(curr->data);
            }
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        reverse(temp.begin(), temp.end());
        res.insert(res.end(), temp.begin(), temp.end());
    }

    vector<int> boundaryTraversal(Node* root) {
        if (!root) return {};
        vector<int> res;
        res.push_back(root->data);
        
        if (root->left || root->right) {
            getLeftBoundary(root, res);
            getLeafNodes(root, res);
            getRightBoundary(root, res);
        }
        
        return res;
    }
