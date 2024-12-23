/*
Problem of the Day: Search in a row-wise sorted matrix
Problem Description: https://www.geeksforgeeks.org/problems/search-in-a-row-wise-sorted-matrix/1
*/

class Solution {
public:
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        for (const auto& row : mat) {
            if (find(row.begin(), row.end(), x) != row.end()) {
                return true;
            }
        }
        return false;
    }
};