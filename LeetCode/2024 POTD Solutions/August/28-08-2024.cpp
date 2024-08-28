/*
Problem of the Day: 1905. Count Sub Islands
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1905-count-sub-islands-leetcode-solution-11b7b0d4a161
*/

class Solution
{
public:
    bool dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j)
    {
        if (i < 0 || i >= grid2.size() || j < 0 || j >= grid2[0].size() || grid2[i][j] == 0)
        {
            return true;
        }

        if (grid1[i][j] == 0)
        {
            return false;
        }

        grid2[i][j] = 0;

        bool isSubIsland = true;
        isSubIsland &= dfs(grid1, grid2, i + 1, j);
        isSubIsland &= dfs(grid1, grid2, i - 1, j);
        isSubIsland &= dfs(grid1, grid2, i, j + 1);
        isSubIsland &= dfs(grid1, grid2, i, j - 1);

        return isSubIsland;
    }

    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int m = grid1.size();
        int n = grid2[0].size();
        int subIslandCount = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid2[i][j] == 1)
                {
                    if (dfs(grid1, grid2, i, j))
                    {
                        subIslandCount++;
                    }
                }
            }
        }

        return subIslandCount;
    }
};