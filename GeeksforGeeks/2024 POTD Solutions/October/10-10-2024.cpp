/*
Problem of the Day: Max distance between same elements
Problem Description: https://medium.com/@pradeepsooryavanshee1210/max-distance-between-same-elements-geeksforgeeks-solution-308b75c5f110
*/

class Solution {
public:
    int maxDistance(vector<int>& arr) {
        unordered_map<int, pair<int, int>> mp;
        int n = arr.size();
        
        for (int i = 0; i < n; ++i) {
            if (mp.find(arr[i]) == mp.end()) {
                mp[arr[i]] = {i, i};
            } else {
                mp[arr[i]].second = i;
            }
        }
        
        int maxDist = 0;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            int distance = it->second.second - it->second.first;
            if (distance > maxDist) {
                maxDist = distance;
            }
        }
        
        return maxDist;
    }
};