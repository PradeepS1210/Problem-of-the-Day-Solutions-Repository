/*
Problem of the Day: 145. Binary Tree Postorder Traversal
Problem Description: https://medium.com/@pradeepsooryavanshee1210/145-binary-tree-postorder-traversal-leetcode-solution-ca04b9aa3a04
*/

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (root == nullptr)
            return result;

        stack<TreeNode *> s1, s2;
        s1.push(root);

        while (!s1.empty())
        {
            TreeNode *node = s1.top();
            s1.pop();
            s2.push(node);

            if (node->left)
                s1.push(node->left);
            if (node->right)
                s1.push(node->right);
        }

        while (!s2.empty())
        {
            result.push_back(s2.top()->val);
            s2.pop();
        }

        return result;
    }
};