/*
Problem of the Day: Alternative Sorting
Problem Description: https://medium.com/@pradeepsooryavanshee1210/alternative-sorting-geeksforgeeks-solution-4dc58039f72a
*/

class Solution {
public:
    vector<int> alternateSort(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        vector<int> result(n);
        
        int left = 0, right = n - 1;
        bool toggle = true;
        
        for (int i = 0; i < n; i++) {
            if (toggle) {
                result[i] = arr[right--];
            } else {
                result[i] = arr[left++];
            }
            toggle = !toggle;
        }
        
        return result;
    }
};
