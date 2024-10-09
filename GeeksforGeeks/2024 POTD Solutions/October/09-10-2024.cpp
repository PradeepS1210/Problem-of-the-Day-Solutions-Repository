/*
Problem of the Day: Linked List Matrix
Problem Description: https://medium.com/@pradeepsooryavanshee1210/linked-list-matrix-geeksforgeeks-solution-a29280a059c3
*/

class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        
        if (n == 0) return nullptr;

        vector<Node*> row_heads(n, nullptr);

        Node* head = nullptr;

        vector<vector<Node*>> nodes(n, vector<Node*>(n, nullptr));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                nodes[i][j] = new Node(mat[i][j]);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j + 1 < n) {
                    nodes[i][j]->right = nodes[i][j + 1];
                }
                
                if (i + 1 < n) {
                    nodes[i][j]->down = nodes[i + 1][j];
                }
            }
        }

        return nodes[0][0];
    }
};