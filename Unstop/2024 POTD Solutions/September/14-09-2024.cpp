/*
Asked in Amazon, Facebook, MakeMyTrip, Swiggy, Pinterest
Problem of the Day: BST Puzzle
Problem Description: https://medium.com/@pradeepsooryavanshee1210/bst-puzzle-unstop-solution-09e8ba9fa41c
*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *createBST()
{
    vector<int> values;
    int value;
    while (cin >> value)
    {
        values.push_back(value);
        if (cin.peek() == '\n')
            break;
    }

    if (values.empty() || values[0] == -1)
        return NULL;

    TreeNode *root = new TreeNode(values[0]);
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;

    while (i < values.size())
    {
        TreeNode *current = q.front();
        q.pop();

        if (i < values.size() && values[i] != -1)
        {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;

        if (i < values.size() && values[i] != -1)
        {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

void helpBST(TreeNode *root, long long &curr, long long &ans)
{
    if (!root)
        return;

    helpBST(root->right, curr, ans);

    curr = (curr + root->val) % MOD;
    ans = (ans + curr) % MOD;

    helpBST(root->left, curr, ans);
}

int main()
{
    TreeNode *root = createBST();

    long long ans = 0;
    long long curr = 0;

    helpBST(root, curr, ans);

    cout << ans << endl;

    return 0;
}