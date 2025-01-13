/*
Problem of the Day: Container With Most Water
Problem Description: https://www.geeksforgeeks.org/problems/container-with-most-water0535/1
*/

class Solution {
public:
    int maxWater(vector<int> &arr) {
        int left = 0, right = arr.size() - 1, maxWater = 0;

        while (left < right) {
            int height = min(arr[left], arr[right]);
            int width = right - left;
            maxWater = max(maxWater, height * width);

            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
    }
};