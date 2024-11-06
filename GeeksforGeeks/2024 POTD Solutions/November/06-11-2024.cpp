/*
Problem of the Day: Root to leaf paths sum
Problem Description: https://medium.com/@pradeepsooryavanshee1210/root-to-leaf-paths-sum-geeksforgeeks-solution-c30595d8f28e
*/

class Solution {
  public:
    int treePathsSumUtil(Node* node, int currentSum) {
        if (node == NULL)
            return 0;

        currentSum = currentSum * 10 + node->data;

        if (node->left == NULL && node->right == NULL)
            return currentSum;

        int leftSum = treePathsSumUtil(node->left, currentSum);
        int rightSum = treePathsSumUtil(node->right, currentSum);

        return leftSum + rightSum;
    }

    int treePathsSum(Node* root) {
        return treePathsSumUtil(root, 0);
    }
};