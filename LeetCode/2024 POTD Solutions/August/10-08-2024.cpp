/*
Problem of the Day: 959. Regions Cut By Slashes
Problem Description: https://medium.com/@pradeepsooryavanshee1210/959-regions-cut-by-slashes-leetcode-solution-3f24b711c658
*/

class Solution
{
public:
    int regionsBySlashes(vector<string> &grid)
    {
        int n = grid.size();
        vector<vector<int>> visited(3 * n, vector<int>(3 * n, 0));
        int regions = 0;

        auto convert = [&](int i, int j)
        {
            if (grid[i][j] == '/')
            {
                visited[3 * i][3 * j + 2] = visited[3 * i + 1][3 * j + 1] = visited[3 * i + 2][3 * j] = 1;
            }
            else if (grid[i][j] == '\\')
            {
                visited[3 * i][3 * j] = visited[3 * i + 1][3 * j + 1] = visited[3 * i + 2][3 * j + 2] = 1;
            }
        };

        function<void(int, int)> dfs = [&](int x, int y)
        {
            if (x < 0 || x >= 3 * n || y < 0 || y >= 3 * n || visited[x][y])
                return;
            visited[x][y] = 1;
            dfs(x + 1, y);
            dfs(x - 1, y);
            dfs(x, y + 1);
            dfs(x, y - 1);
        };

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                convert(i, j);
            }
        }

        for (int i = 0; i < 3 * n; ++i)
        {
            for (int j = 0; j < 3 * n; ++j)
            {
                if (!visited[i][j])
                {
                    dfs(i, j);
                    ++regions;
                }
            }
        }

        return regions;
    }
};
