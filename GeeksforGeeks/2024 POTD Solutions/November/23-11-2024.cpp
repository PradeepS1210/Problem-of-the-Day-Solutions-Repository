/*
Asked in MicrosoftAdobe
Problem of the Day: Minimize the Heights II
Problem Description: https://medium.com/@pradeepsooryavanshee1210/minimize-the-heights-ii-geeksforgeeks-solution-9b60b8adef51
*/

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int result = arr[n - 1] - arr[0];
        
        for (int i = 0; i < n - 1; i++) {
            int currentMax = max(arr[i] + k, arr[n - 1] - k);
            int currentMin = min(arr[0] + k, arr[i + 1] - k);

            if (currentMin < 0) continue;

            result = min(result, currentMax - currentMin);
        }
        
        return result;
    }
};