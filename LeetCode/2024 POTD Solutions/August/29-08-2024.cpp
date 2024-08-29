/*
Problem of the Day: 947. Most Stones Removed with Same Row or Column
Problem Description: https://medium.com/@pradeepsooryavanshee1210/947-most-stones-removed-with-same-row-or-column-leetcode-solution-d71bcc9f86a8
*/

class Solution
{
public:
    int find(int x, unordered_map<int, int> &parent)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }

    void unite(int x, int y, unordered_map<int, int> &parent, unordered_map<int, int> &rank)
    {
        int rootX = find(x, parent);
        int rootY = find(y, parent);
        if (rootX != rootY)
        {
            if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    int removeStones(vector<vector<int>> &stones)
    {
        unordered_map<int, int> parent, rank;

        for (const auto &stone : stones)
        {
            int x = stone[0];
            int y = ~stone[1]; // Using bitwise NOT (~) to differentiate row and column indices
            if (parent.find(x) == parent.end())
            {
                parent[x] = x;
                rank[x] = 0;
            }
            if (parent.find(y) == parent.end())
            {
                parent[y] = y;
                rank[y] = 0;
            }
            unite(x, y, parent, rank);
        }

        unordered_set<int> uniqueRoots;
        for (const auto &stone : stones)
        {
            int root = find(stone[0], parent);
            uniqueRoots.insert(root);
        }

        return stones.size() - uniqueRoots.size();
    }
};