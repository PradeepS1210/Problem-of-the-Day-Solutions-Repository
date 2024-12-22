/*
Asked in Paytm, Accolite, Amazon, Microsoft
Problem of the Day: Search in a Row-Column sorted matrix
Problem Description: https://www.geeksforgeeks.org/problems/search-in-a-matrix17201720/1
*/

class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        
        int i = 0, j = m - 1;
        
        while (i < n && j >= 0) {
            if (mat[i][j] == x) {
                return true;
            } else if (mat[i][j] > x) {
                j--;
            } else {
                i++;
            }
        }
        
        return false;
    }
};