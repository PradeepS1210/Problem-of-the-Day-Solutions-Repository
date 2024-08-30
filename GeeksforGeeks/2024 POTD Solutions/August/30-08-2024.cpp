/*
Asked in Accolite, Amazon, Microsoft, D-E-Shaw, Visa, MAQ Software, Amdocs, Twitter
Problem of the Day: N-Queen Problem
Problem Description: https://medium.com/@pradeepsooryavanshee1210/n-queen-problem-geeksforgeeks-solution-108a97aedb3a
*/

class Solution
{
public:
    vector<vector<int>> nQueen(int n)
    {
        vector<vector<int>> result;
        vector<int> board(n, 0);
        vector<bool> columns(n, false);
        vector<bool> diagonals1(2 * n - 1, false);
        vector<bool> diagonals2(2 * n - 1, false);
        solve(0, n, board, result, columns, diagonals1, diagonals2);
        return result;
    }

private:
    void solve(int row, int n, vector<int> &board, vector<vector<int>> &result,
               vector<bool> &columns, vector<bool> &diagonals1, vector<bool> &diagonals2)
    {
        if (row == n)
        {
            result.push_back(board);
            return;
        }
        for (int col = 0; col < n; ++col)
        {
            if (columns[col] || diagonals1[row + col] || diagonals2[row - col + n - 1])
            {
                continue;
            }
            board[row] = col + 1;
            columns[col] = diagonals1[row + col] = diagonals2[row - col + n - 1] = true;
            solve(row + 1, n, board, result, columns, diagonals1, diagonals2);
            // Backtrack
            columns[col] = diagonals1[row + col] = diagonals2[row - col + n - 1] = false;
        }
    }
};