/*
Problem of the Day: Construct Tree from Inorder & Preorder
Problem Description: https://www.geeksforgeeks.org/problems/construct-tree-1/1
*/

class Solution {
public:
    int preIndex = 0;
    unordered_map<int, int> inorderMap;

    Node* buildTreeUtil(vector<int> &inorder, vector<int> &preorder, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return NULL;
        }

        int curr = preorder[preIndex++];
        Node* node = new Node(curr);

        if (inStart == inEnd) {
            return node;
        }

        int inIndex = inorderMap[curr];

        node->left = buildTreeUtil(inorder, preorder, inStart, inIndex - 1);
        node->right = buildTreeUtil(inorder, preorder, inIndex + 1, inEnd);

        return node;
    }

    Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return buildTreeUtil(inorder, preorder, 0, inorder.size() - 1);
    }

};
