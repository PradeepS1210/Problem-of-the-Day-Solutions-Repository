/*
Problem of the Day: Find the number of islands
Problem Description: https://medium.com/@pradeepsooryavanshee1210/find-the-number-of-islands-geeksforgeeks-solution-6d6e52f7ab1a
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    count++;

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';

                    while (!q.empty()) {
                        pair<int, int> current = q.front();
                        q.pop();

                        for (int k = 0; k < 8; ++k) {
                            int newX = current.first + dx[k];
                            int newY = current.second + dy[k];

                            if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == '1') {
                                q.push({newX, newY});
                                grid[newX][newY] = '0';
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};