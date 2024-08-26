/*
Problem of the Day: 590. N-ary Tree Postorder Traversal
Problem Description: https://medium.com/@pradeepsooryavanshee1210/590-n-ary-tree-postorder-traversal-leetcode-solution-64f92db26db0
*/

class Solution
{
public:
    vector<int> postorder(Node *root)
    {
        vector<int> result;
        if (root == nullptr)
        {
            return result;
        }

        for (Node *child : root->children)
        {
            vector<int> childResult = postorder(child);
            result.insert(result.end(), childResult.begin(), childResult.end());
        }

        result.push_back(root->val);
        return result;
    }
};