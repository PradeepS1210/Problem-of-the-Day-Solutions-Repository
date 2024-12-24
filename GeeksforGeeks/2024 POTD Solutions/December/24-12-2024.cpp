/*
Problem of the Day: Search in a sorted Matrix
Problem Description: https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int rows = mat.size();
        int cols = mat[0].size();

        int start = 0, end = rows * cols - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int midElement = mat[mid / cols][mid % cols];
            // int row_index = mid / M;
            // int col_index = mid % M;
            
            if (midElement == x) {
                return true;
            } else if (midElement < x) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }
};