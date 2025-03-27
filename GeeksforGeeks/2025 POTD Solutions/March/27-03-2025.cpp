/*
Problem of the Day: Minimum Platforms
Problem Description: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
*/

class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();

        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int platforms_needed = 1;
        int max_platforms = 1;
        
        int i = 1, j = 0;
        
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                platforms_needed++;
                i++;
            }
            else {
                platforms_needed--;
                j++;
            }
            
            max_platforms = max(max_platforms, platforms_needed);
        }
        
        return max_platforms;
    }
};
