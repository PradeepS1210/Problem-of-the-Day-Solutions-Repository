/*
Asked in Avizva, Cognizant, L&T
Problem of the Day: Playing with Tree
Problem Description: https://medium.com/@pradeepsooryavanshee1210/playing-with-tree-unstop-solution-8d8901872d7e
*/

#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *insertNode(TreeNode *root, int val)
{
    if (root == NULL)
    {
        return new TreeNode(val);
    }
    if (val < root->val)
    {
        root->left = insertNode(root->left, val);
    }
    else
    {
        root->right = insertNode(root->right, val);
    }
    return root;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->val < p->val && root->val < q->val)
    {
        return lowestCommonAncestor(root->right, p, q);
    }

    if (root->val > p->val && root->val > q->val)
    {
        return lowestCommonAncestor(root->left, p, q);
    }

    return root;
}

int main()
{
    int n;
    cin >> n;

    TreeNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        root = insertNode(root, value);
    }

    int x, y;
    cin >> x >> y;

    TreeNode *p = new TreeNode(x);
    TreeNode *q = new TreeNode(y);

    TreeNode *lca = lowestCommonAncestor(root, p, q);
    cout << lca->val << endl;

    return 0;
}