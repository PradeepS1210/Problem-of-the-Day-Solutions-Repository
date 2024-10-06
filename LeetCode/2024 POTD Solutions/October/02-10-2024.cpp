/*
Problem of the Day: 1331. Rank Transform of an Array
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1331-rank-transform-of-an-array-leetcode-solution-35bcc24f4fd4
*/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        unordered_map<int, int> rankMap;
        int rank = 1;
        
        for (int num : sortedArr) {
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank;
                rank++;
            }
        }
        
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = rankMap[arr[i]];
        }
        
        return arr;
    }
};