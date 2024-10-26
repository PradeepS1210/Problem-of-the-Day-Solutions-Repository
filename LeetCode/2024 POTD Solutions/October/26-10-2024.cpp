/*
Problem of the Day: 2458. Height of Binary Tree After Subtree Removal Queries
Problem Description: https://medium.com/@pradeepsooryavanshee1210/2458-height-of-binary-tree-after-subtree-removal-queries-leetcode-solution-010bde272104
*/

class Solution {
public:
    unordered_map<int, int> depth;
    unordered_map<int, int> height;
    unordered_map<int, vector<int>> depthHeights;
    
    int dfs(TreeNode* node, int d) {
        if (!node) return -1;
        depth[node->val] = d;
        int leftHeight = dfs(node->left, d + 1);
        int rightHeight = dfs(node->right, d + 1);
        int h = 1 + max(leftHeight, rightHeight);
        height[node->val] = h;
        depthHeights[d].push_back(h);
        return h;
    }
    
    void preprocessDepthHeights() {
        for (auto& [d, heights] : depthHeights) {
            sort(heights.rbegin(), heights.rend());
            if (heights.size() > 2) {
                heights.resize(2); 
            }
        }
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root, 0);
        preprocessDepthHeights();
        
        vector<int> result;
        
        int originalHeight = height[root->val];
        
        for (int q : queries) {
            int d = depth[q];
            int h = height[q];
            
            if (depthHeights[d].size() == 1) {
                result.push_back(originalHeight - h - 1);
            } else {
                int maxHeightWithoutNode = (depthHeights[d][0] == h) ? depthHeights[d][1] : depthHeights[d][0];
                result.push_back(d + maxHeightWithoutNode);
            }
        }
        
        return result;
    }
};
