/*
Problem of the Day: 1975. Maximum Matrix Sum
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1975-maximum-matrix-sum-leetcode-solution-bd97e1e75939
*/

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int negativeCount = 0;
        int minAbsValue = INT_MAX;
        
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                totalSum += abs(matrix[i][j]);
                if (matrix[i][j] < 0) {
                    ++negativeCount;
                }
                minAbsValue = min(minAbsValue, abs(matrix[i][j]));
            }
        }
        
        if (negativeCount % 2 == 1) {
            totalSum -= 2 * minAbsValue;
        }
        
        return totalSum;
    }
};