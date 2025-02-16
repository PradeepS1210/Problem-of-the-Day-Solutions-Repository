/*
Problem of the Day: Serialize and deserialize a binary tree
Problem Description: https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1
*/

class Solution {
  public:
    vector<int> serialize(Node *root) {
        vector<int> result;
        if (root == nullptr) return result;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            
            if (current) {
                result.push_back(current->data);
                q.push(current->left);
                q.push(current->right);
            } else {
                result.push_back(INT_MIN);
            }
        }
        return result;
    }

    Node* deSerialize(vector<int> &arr) {
        if (arr.empty()) return nullptr;
        
        Node* root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);
        
        int i = 1;
        while (!q.empty() && i < arr.size()) {
            Node* current = q.front();
            q.pop();
            
            if (arr[i] != INT_MIN) {
                current->left = new Node(arr[i]);
                q.push(current->left);
            }
            i++;
            
            if (i < arr.size() && arr[i] != INT_MIN) {
                current->right = new Node(arr[i]);
                q.push(current->right);
            }
            i++;
        }
        return root;
    }
};
