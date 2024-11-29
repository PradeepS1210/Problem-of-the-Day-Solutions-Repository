/*
Problem of the Day: 2577. Minimum Time to Visit a Cell In a Grid
Problem Description: https://medium.com/@pradeepsooryavanshee1210/2577-minimum-time-to-visit-a-cell-in-a-grid-leetcode-solution-d66c3bc6d673
*/

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if (grid[1][0] > 1 && grid[0][1] > 1) return -1;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        pq.emplace(0, 0, 0);

        while (!pq.empty()) {
            auto [time, row, col] = pq.top();
            pq.pop();

            if (row == m - 1 && col == n - 1) return time;

            if (visited[row][col]) continue;
            visited[row][col] = true;

            for (auto [dr, dc] : directions) {
                int newRow = row + dr, newCol = col + dc;

                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !visited[newRow][newCol]) {
                    int wait = max(0, grid[newRow][newCol] - time - 1);
                    if ((wait % 2) == 1) wait++;
                    int newTime = time + 1 + wait;

                    pq.emplace(newTime, newRow, newCol);
                }
            }
        }

        return -1;
    }
};