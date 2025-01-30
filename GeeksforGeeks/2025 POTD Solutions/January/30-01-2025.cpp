/*
Problem of the Day: N-Queen Problem
Problem Description: https://www.geeksforgeeks.org/problems/n-queen-problem0315/1
*/

class Solution {
private:
    vector<vector<int>> results;
    
    void solve(int n, int row, vector<int>& placement) {
        if (row == n) {
            results.push_back(placement);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (isValid(placement, row, col)) {
                placement[row] = col + 1;
                solve(n, row + 1, placement);
                placement[row] = 0;
            }
        }
    }
    
    bool isValid(const vector<int>& placement, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (placement[i] == col + 1 || 
                abs(placement[i] - (col + 1)) == abs(i - row)) {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<int>> nQueen(int n) {
        results.clear();
        vector<int> placement(n, 0);
        solve(n, 0, placement);
        return results;
    }
};
