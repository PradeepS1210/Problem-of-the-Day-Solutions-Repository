/*
Problem of the Day: 1277. Count Square Submatrices with All Ones
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1277-count-square-submatrices-with-all-ones-leetcode-solution-3163b707992b
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int count = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 1 && i > 0 && j > 0) {
                    matrix[i][j] = min({matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]}) + 1;
                }
                count += matrix[i][j];
            }
        }
        
        return count;
    }
};
