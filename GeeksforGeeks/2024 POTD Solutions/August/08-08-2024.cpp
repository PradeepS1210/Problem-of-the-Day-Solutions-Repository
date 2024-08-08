/*
Asked in Amazon, Microsoft, D-E-Shaw, Goldman Sachs, and Adobe
Problem of the Day: Sum Tree
Problem Description: https://medium.com/@pradeepsooryavanshee1210/sum-tree-geeksforgeeks-solution-problem-of-the-day-49fc9e21059c
*/

class Solution
{
public:
    bool isSumTreeUtil(Node *node, int &sum)
    {
        if (node == nullptr)
        {
            sum = 0;
            return true;
        }

        if (node->left == nullptr && node->right == nullptr)
        {
            sum = node->data;
            return true;
        }

        int leftSum = 0, rightSum = 0;
        bool leftIsSumTree = isSumTreeUtil(node->left, leftSum);
        bool rightIsSumTree = isSumTreeUtil(node->right, rightSum);

        sum = node->data + leftSum + rightSum;

        if (leftIsSumTree && rightIsSumTree && node->data == leftSum + rightSum)
        {
            return true;
        }

        return false;
    }

    bool isSumTree(Node *root)
    {
        int sum = 0;
        return isSumTreeUtil(root, sum);
    }
};
