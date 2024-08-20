/*
Asked in Flipkart, Amazon, Microsoft, Adobe
Problem of the Day: Burning Tree
Problem Description: https://medium.com/@pradeepsooryavanshee1210/burning-tree-geeksforgeeks-solution-1e56c34a57be
*/

class Solution
{
public:
    Node *findTarget(Node *root, int target, std::unordered_map<Node *, Node *> &parentMap)
    {
        std::queue<Node *> q;
        q.push(root);
        Node *targetNode = nullptr;

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            if (curr->data == target)
            {
                targetNode = curr;
            }

            if (curr->left)
            {
                parentMap[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right)
            {
                parentMap[curr->right] = curr;
                q.push(curr->right);
            }
        }

        return targetNode;
    }

    int burnTree(Node *targetNode, std::unordered_map<Node *, Node *> &parentMap)
    {
        std::queue<Node *> q;
        std::unordered_map<Node *, bool> visited;
        q.push(targetNode);
        visited[targetNode] = true;

        int time = 0;

        while (!q.empty())
        {
            int size = q.size();
            bool flag = false;

            for (int i = 0; i < size; i++)
            {
                Node *curr = q.front();
                q.pop();

                if (curr->left && !visited[curr->left])
                {
                    flag = true;
                    visited[curr->left] = true;
                    q.push(curr->left);
                }

                if (curr->right && !visited[curr->right])
                {
                    flag = true;
                    visited[curr->right] = true;
                    q.push(curr->right);
                }

                if (parentMap[curr] && !visited[parentMap[curr]])
                {
                    flag = true;
                    visited[parentMap[curr]] = true;
                    q.push(parentMap[curr]);
                }
            }

            if (flag)
            {
                time++;
            }
        }

        return time;
    }

    int minTime(Node *root, int target)
    {
        if (!root)
            return 0;

        std::unordered_map<Node *, Node *> parentMap;
        Node *targetNode = findTarget(root, target, parentMap);

        return burnTree(targetNode, parentMap);
    }
};