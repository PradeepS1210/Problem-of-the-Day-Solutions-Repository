/*
Problem of the Day: Print the total sum of every corner element
Problem Description: https://unstop.com/code/practice/306512
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insertBST(TreeNode* root, int value) {
    if (root == NULL) {
        return new TreeNode(value);
    }
    if (value < root->val) {
        root->left = insertBST(root->left, value);
    } else {
        root->right = insertBST(root->right, value);
    }
    return root;
}

TreeNode* constructBST(vector<int>& preorder) {
    TreeNode* root = NULL;
    for (int value : preorder) {
        root = insertBST(root, value);
    }
    return root;
}

int sumOfCorners(TreeNode* root) {
    if (root == NULL) return 0;

    queue<TreeNode*> q;
    q.push(root);
    int totalSum = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (i == 0 || i == size - 1) {
                totalSum += node->val;
            }
            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
        }
    }
    return totalSum;
}

int main() {
    int N;
    cin >> N;
    vector<int> preorder(N);
    for (int i = 0; i < N; ++i) {
        cin >> preorder[i];
    }

    TreeNode* root = constructBST(preorder);
    int result = sumOfCorners(root);
    cout << result << endl;

    return 0;
}
