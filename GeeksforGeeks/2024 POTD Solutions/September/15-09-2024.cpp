/*
Asked in Morgan Stanley, Accolite, Amazon, Microsoft, Snapdeal,Goldman Sachs, Salesforce
Problem of the Day: Binary Tree to DLL
Problem Description: https://medium.com/@pradeepsooryavanshee1210/binary-tree-to-dll-geeksforgeeks-solution-abf56f0c1c2f
*/

class Solution
{
public:
    Node *head = NULL;
    Node *prev = NULL;

    Node *bToDLL(Node *root)
    {
        if (root == NULL)
            return NULL;

        bToDLL(root->left);

        if (prev == NULL)
        {
            head = root;
        }
        else
        {
            root->left = prev;
            prev->right = root;
        }

        prev = root;

        bToDLL(root->right);

        return head;
    }
};