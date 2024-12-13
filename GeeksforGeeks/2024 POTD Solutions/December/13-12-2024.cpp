/*
Problem of the Day: Sorted and Rotated Minimum
Problem Description: https://medium.com/@pradeepsooryavanshee1210/sorted-and-rotated-minimum-geeksforgeeks-solution-b06f49a175b9
*/

class Solution {
  public:
    int findMin(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] > arr[right]) {
                left = mid + 1;
            } else if (arr[mid] < arr[right]) {
                right = mid;
            } else {
                right--;
            }
        }
        
        return arr[left];
    }
};