/*
Asked in Yahoo, Flipkart, Coursera, Cisco
Problem of the Day: Alice’s App
problem Description: https://medium.com/@pradeepsooryavanshee1210/alices-app-unstop-solution-8b46705bcd8d
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(vector<string> &nodes)
{
    if (nodes.empty() || nodes[0] == "N")
        return NULL;

    TreeNode *root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (i < nodes.size())
    {
        TreeNode *current = q.front();
        q.pop();

        if (nodes[i] != "N")
        {
            current->left = new TreeNode(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "N")
        {
            current->right = new TreeNode(stoi(nodes[i]));
            q.push(current->right);
        }
        i++;
    }
    return root;
}

vector<int> leftView(TreeNode *root)
{
    vector<int> result;
    if (!root)
        return result;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++)
        {
            TreeNode *current = q.front();
            q.pop();

            if (i == 0)
            {
                result.push_back(current->val); // First node of each level
            }

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<string> nodes(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nodes[i];
    }

    TreeNode *root = buildTree(nodes);
    vector<int> leftViewNodes = leftView(root);

    for (int val : leftViewNodes)
    {
        cout << val << " ";
    }

    return 0;
}
