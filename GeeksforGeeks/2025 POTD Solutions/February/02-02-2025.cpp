/*
Problem of the Day: Level order traversal
Problem Description: https://www.geeksforgeeks.org/problems/level-order-traversal/1
*/

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;
            for (int i = 0; i < levelSize; i++) {
                Node* currentNode = q.front();
                q.pop();
                currentLevel.push_back(currentNode->data);
                
                if (currentNode->left != nullptr) {
                    q.push(currentNode->left);
                }
                
                if (currentNode->right != nullptr) {
                    q.push(currentNode->right);
                }
            }
            result.push_back(currentLevel);
        }
        
        return result;
    }
};
