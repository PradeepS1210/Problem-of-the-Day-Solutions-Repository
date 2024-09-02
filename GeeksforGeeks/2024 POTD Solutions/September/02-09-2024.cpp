/*
Asked in Amazon, Microsoft, Samsung, MakeMyTrip, Goldman Sachs
Problem of the Day: Minimum Cost Path
Problem Description: https://medium.com/@pradeepsooryavanshee1210/minimum-cost-path-geeksforgeeks-solution-d1802e26d12f
*/

class Solution
{
public:
    int minimumCostPath(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
        cost[0][0] = grid[0][0];

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};

        while (!pq.empty())
        {
            pair<int, pair<int, int>> top = pq.top();
            pq.pop();

            int currentCost = top.first;
            int x = top.second.first;
            int y = top.second.second;

            if (x == n - 1 && y == n - 1)
            {
                return currentCost;
            }

            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n)
                {
                    int newCost = currentCost + grid[nx][ny];

                    if (newCost < cost[nx][ny])
                    {
                        cost[nx][ny] = newCost;
                        pq.push({newCost, {nx, ny}});
                    }
                }
            }
        }

        return cost[n - 1][n - 1];
    }
};