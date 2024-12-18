/*
Problem of the Day: Allocate Minimum Pages
Problem Descripition: https://medium.com/@pradeepsooryavanshee1210/allocate-minimum-pages-geeksforgeeks-solution-e819361833c6
*/

class Solution {
public:
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1;
        
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int result = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(arr, n, k, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
    
private:
    bool isValid(vector<int> &arr, int n, int k, int maxPages) {
        int studentCount = 1, currentSum = 0;
        
        for (int i = 0; i < n; ++i) {
            if (currentSum + arr[i] > maxPages) {
                studentCount++;
                currentSum = arr[i];
                if (studentCount > k) return false;
            } else {
                currentSum += arr[i];
            }
        }
        return true;
    }
};