/*
Asked in Amazon, Microsoft, Apple, IBM, Dell
Problem of the Day: Mathew and trees
Problem Description: https://medium.com/@pradeepsooryavanshee1210/mathew-and-trees-unstop-solution-2aec210dc8f9
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    TreeNode *root = new TreeNode(arr[0]);
    queue<TreeNode *> q;
    q.push(root);

    int idx = 1;
    while (!q.empty() && idx < n)
    {
        TreeNode *current = q.front();
        q.pop();

        if (idx < n && arr[idx] != -1)
        {
            current->left = new TreeNode(arr[idx]);
            q.push(current->left);
        }
        idx++;

        if (idx < n && arr[idx] != -1)
        {
            current->right = new TreeNode(arr[idx]);
            q.push(current->right);
        }
        idx++;
    }

    vector<vector<int>> result;
    queue<TreeNode *> level_q;
    level_q.push(root);

    while (!level_q.empty())
    {
        int size = level_q.size();
        vector<int> level;

        for (int i = 0; i < size; ++i)
        {
            TreeNode *node = level_q.front();
            level_q.pop();
            level.push_back(node->val);

            if (node->left)
                level_q.push(node->left);
            if (node->right)
                level_q.push(node->right);
        }
        result.push_back(level);
    }

    cout << result.size() << endl;
    for (const auto &level : result)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}