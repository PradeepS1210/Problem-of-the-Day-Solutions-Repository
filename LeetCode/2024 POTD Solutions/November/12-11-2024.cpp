/*
Problem of the Day: 2070. Most Beautiful Item for Each Query
Problem Description: https://medium.com/@pradeepsooryavanshee1210/2070-most-beautiful-item-for-each-query-leetcode-solution-c66f35aec893
*/

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        
        int n = items.size();
        vector<int> maxBeauty(n);
        maxBeauty[0] = items[0][1];
        for (int i = 1; i < n; ++i) {
            maxBeauty[i] = max(maxBeauty[i - 1], items[i][1]);
        }
        
        vector<int> result;
        for (int q : queries) {
            auto it = upper_bound(items.begin(), items.end(), vector<int>{q, INT_MAX});
            int idx = it - items.begin() - 1;
            if (idx >= 0) {
                result.push_back(maxBeauty[idx]);
            } else {
                result.push_back(0);
            }
        }
        
        return result;
    }
};