/*
Problem of the Day: Product array puzzle
Problem Description: https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, 1);
        vector<int> left(n, 1);
        vector<int> right(n, 1);

        for (int i = 1; i < n; i++) {
            left[i] = left[i-1] * arr[i-1];
        }

        for (int i = n-2; i >= 0; i--) {
            right[i] = right[i+1] * arr[i+1];
        }

        for (int i = 0; i < n; i++) {
            res[i] = left[i] * right[i];
        }

        return res;
    }
};