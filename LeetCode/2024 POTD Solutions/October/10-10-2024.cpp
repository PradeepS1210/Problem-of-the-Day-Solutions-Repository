/*
Problem of the Day: 962. Maximum Width Ramp
Problem Description: https://medium.com/@pradeepsooryavanshee1210/962-maximum-width-ramp-leetcode-solution-23b87cb63c8b
*/

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        int maxWidth = 0;

        for (int i = 0; i < n; ++i) {
            if (st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }

        for (int j = n - 1; j >= 0; --j) {
            while (!st.empty() && nums[st.top()] <= nums[j]) {
                maxWidth = max(maxWidth, j - st.top());
                st.pop();
            }
        }

        return maxWidth;
    }
};