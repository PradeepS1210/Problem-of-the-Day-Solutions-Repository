/*
Problem of the Day: Spirally traversing a matrix
Problem Description: https://medium.com/@pradeepsooryavanshee1210/spirally-traversing-a-matrix-geeksforgeeks-solution-6fa2f09da0f7
*/

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        vector<int> result;
        int n = mat.size();
        int m = mat[0].size();
        
        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        
        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                result.push_back(mat[top][i]);
            }
            top++;
            
            for (int i = top; i <= bottom; i++) {
                result.push_back(mat[i][right]);
            }
            right--;
            
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result.push_back(mat[bottom][i]);
                }
                bottom--;
            }
            
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(mat[i][left]);
                }
                left++;
            }
        }
        
        return result;
    }
};