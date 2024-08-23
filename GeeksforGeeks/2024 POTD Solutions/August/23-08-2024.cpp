/*
Asked in Paytm,Flipkart, Accolite, Amazon, OYO Rooms, Samsung, Snapdeal, MakeMyTrip, Ola Cabs, Adobe, Qualcomm, Twitter, Knowlarity, Open Solutions
Problem of the Day: Left View of Binary Tree
Problem Description: https://medium.com/@pradeepsooryavanshee1210/left-view-of-binary-tree-geeksforgeeks-solution-66330d5e3f10
*/

// Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> result;
    if (root == NULL)
        return result;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (i == 1)
            {
                result.push_back(temp->data);
            }

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }

    return result;
}