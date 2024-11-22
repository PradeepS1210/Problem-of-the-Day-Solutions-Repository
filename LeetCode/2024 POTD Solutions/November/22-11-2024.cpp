/*
Problem of the Day: 1072. Flip Columns For Maximum Number of Equal Rows
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1072-flip-columns-for-maximum-number-of-equal-rows-leetcode-solution-64d1189b2f91
*/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patternCount;

        for(auto& row : matrix) {
            string pattern, flippedPattern;
            for(int val : row) {
                pattern += (val == 0 ? '0' : '1');
                flippedPattern += (val == 0 ? '1' : '0');
            }
            patternCount[pattern]++;
            patternCount[flippedPattern]++;
        }

        int maxRows = 0;
        for(auto& [pattern, count] : patternCount) {
            maxRows = max(maxRows, count);
        }
        return maxRows;
    }
};