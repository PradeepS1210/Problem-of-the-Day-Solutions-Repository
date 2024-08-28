/*
Asked in Yahoo, Indeed, Spotify
Problem of the Day: Subtree of Another Tree
Problem Description: https://medium.com/@pradeepsooryavanshee1210/subtree-of-another-tree-unstop-solution-050deaa835f1
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *buildTree(const vector<string> &nodes);
bool isSubtree(TreeNode *tree1, TreeNode *tree2);
bool isSameTree(TreeNode *tree1, TreeNode *tree2);

TreeNode *buildTree(const vector<string> &nodes)
{
    if (nodes.empty())
        return nullptr;

    TreeNode *root = nullptr;
    queue<TreeNode **> q;
    q.push(&root);

    for (const string &val : nodes)
    {
        TreeNode **node = q.front();
        q.pop();

        if (val == "null")
        {
            *node = nullptr;
        }
        else
        {
            *node = new TreeNode(stoi(val));
            q.push(&((*node)->left));
            q.push(&((*node)->right));
        }
    }

    return root;
}

bool isSubtree(TreeNode *tree1, TreeNode *tree2)
{
    if (!tree2)
        return true;
    if (!tree1)
        return false;

    if (isSameTree(tree1, tree2))
        return true;
    return isSubtree(tree1->left, tree2) || isSubtree(tree1->right, tree2);
}

bool isSameTree(TreeNode *tree1, TreeNode *tree2)
{
    if (!tree1 && !tree2)
        return true;
    if (!tree1 || !tree2)
        return false;

    return (tree1->val == tree2->val) &&
           isSameTree(tree1->left, tree2->left) &&
           isSameTree(tree1->right, tree2->right);
}

int main()
{
    int N, M;
    cin >> N;

    vector<string> countriesA(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> countriesA[i];
    }

    cin >> M;
    vector<string> countriesB(M);
    for (int i = 0; i < M; ++i)
    {
        cin >> countriesB[i];
    }

    TreeNode *rootA = buildTree(countriesA);
    TreeNode *rootB = buildTree(countriesB);

    if (isSubtree(rootA, rootB))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}