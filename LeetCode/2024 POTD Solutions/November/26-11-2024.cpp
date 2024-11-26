/*
Problem of the Day: 2924. Find Champion II
Problem Description: https://medium.com/@pradeepsooryavanshee1210/2924-find-champion-ii-leetcode-solution-b0acd86d2f9c
*/

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n, 0);
        
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            inDegree[v]++;
        }
        
        int champion = -1;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                if (champion != -1) return -1;
                champion = i;
            }
        }
        
        return champion;
    }
};