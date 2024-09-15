/*
Asked in Flipkart, bloomberg, nvidia
Problem of the Day: Special Binary Tree using String
Problem Description: https://medium.com/@pradeepsooryavanshee1210/special-binary-tree-using-string-unstop-solution-07abc1ba2d26
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> levelOrder(TreeNode *root)
{
    vector<int> result;
    if (root == nullptr)
    {
        return result;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        if (node)
        {
            result.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        }
        else
        {
            result.push_back(-1);
        }
    }

    return result;
}

TreeNode *constructTree(const string &traversal)
{
    if (traversal.empty())
    {
        return nullptr;
    }

    TreeNode *root = nullptr;
    vector<TreeNode *> stack;
    size_t pos = 0;

    while (pos < traversal.size())
    {
        int depth = 0;
        while (pos < traversal.size() && traversal[pos] == '-')
        {
            ++depth;
            ++pos;
        }

        int val = 0;
        while (pos < traversal.size() && isdigit(traversal[pos]))
        {
            val = val * 10 + (traversal[pos] - '0');
            ++pos;
        }

        TreeNode *node = new TreeNode(val);

        while (stack.size() > depth)
        {
            stack.pop_back();
        }

        if (!stack.empty())
        {
            TreeNode *parent = stack.back();
            if (parent->left == nullptr)
            {
                parent->left = node;
            }
            else
            {
                parent->right = node;
            }
        }

        if (root == nullptr)
        {
            root = node;
        }

        stack.push_back(node);
    }

    return root;
}

int main()
{
    string input;
    getline(cin, input);

    TreeNode *root = constructTree(input);
    vector<int> result = levelOrder(root);

    cout << "[";
    for (size_t i = 0; i < result.size(); ++i)
    {
        if (result[i] == -1)
        {
            cout << "null";
        }
        else
        {
            cout << result[i];
        }
        if (i < result.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}