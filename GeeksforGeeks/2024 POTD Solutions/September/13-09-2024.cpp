/*
Problem of the Day :Mirror Tree
Problem Description: https://medium.com/@pradeepsooryavanshee1210/mirror-tree-geeksforgeeks-solution-6ae6c13bc65a
*/

class Solution
{
public:
    void mirror(Node *node)
    {
        if (node == nullptr)
            return;

        mirror(node->left);
        mirror(node->right);

        Node *temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};

void printInorder(Node *root)
{
    if (root == nullptr)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}