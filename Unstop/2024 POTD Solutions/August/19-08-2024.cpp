/*
Asked in Qualcomm, IBM, Atlassian
Problem of the Day: Meet Point
Problem Description: https://medium.com/@pradeepsooryavanshee1210/ibm-interview-question-meet-point-unstop-solution-705821d28617
*/

#include <iostream>
#include <queue>
#include <unordered_map>
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

    while (!q.empty() && i < nodes.size())
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

TreeNode *findLCA(TreeNode *root, int p, int q)
{
    if (root == NULL || root->val == p || root->val == q)
        return root;

    TreeNode *left = findLCA(root->left, p, q);
    TreeNode *right = findLCA(root->right, p, q);

    if (left != NULL && right != NULL)
        return root;
    return (left != NULL) ? left : right;
}

int main()
{
    int N;
    cin >> N;
    vector<string> nodes(N);

    for (int i = 0; i < N; i++)
    {
        cin >> nodes[i];
    }

    int P, Q;
    cin >> P >> Q;

    TreeNode *root = buildTree(nodes);

    TreeNode *lca = findLCA(root, P, Q);

    cout << lca->val << endl;

    return 0;
}