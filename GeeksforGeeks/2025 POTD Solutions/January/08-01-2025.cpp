/*
Problem of the Day: Count the number of possible triangles
Problem Description: https://www.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1
*/

class Solution {
public:
    int countTriangles(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int count = 0;

        for (int i = n-1; i >= 2; i--) {
            int left = 0, right = i-1;
            while (left < right) {
                if (arr[left] + arr[right] > arr[i]) {
                    count += (right - left);
                    right--;
                } else {
                    left++;
                }
            }
        }

        return count;
    }
};