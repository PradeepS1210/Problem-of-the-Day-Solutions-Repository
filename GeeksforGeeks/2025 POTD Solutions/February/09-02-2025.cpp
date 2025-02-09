/*
Problem of the Day: Maximum path sum from any node
Problem Description: https://www.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1
*/

class Solution {
  public:
    int findMaxSum(Node* root) {
        int maxSum = INT_MIN;
        findMaxUtil(root, maxSum);
        return maxSum;
    }

  private:
    int findMaxUtil(Node* node, int& maxSum) {
        if (node == nullptr) return 0;

        int leftMax = max(findMaxUtil(node->left, maxSum), 0);
        int rightMax = max(findMaxUtil(node->right, maxSum), 0);

        int currentMax = node->data + leftMax + rightMax;

        maxSum = max(maxSum, currentMax);

        return node->data + max(leftMax, rightMax);
    }
};
