/*
Problem of the Day: 1861. Rotating the Box
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1861-rotating-the-box-leetcode-solution-2d5438e87ae0
*/

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();

        for (int i = 0; i < m; ++i) {
            int empty = n - 1;
            for (int j = n - 1; j >= 0; --j) {
                if (box[i][j] == '*') {
                    empty = j - 1;
                } else if (box[i][j] == '#') {
                    box[i][j] = '.';
                    box[i][empty--] = '#';
                }
            }
        }

        vector<vector<char>> rotatedBox(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rotatedBox[j][m - i - 1] = box[i][j];
            }
        }

        return rotatedBox;
    }
};