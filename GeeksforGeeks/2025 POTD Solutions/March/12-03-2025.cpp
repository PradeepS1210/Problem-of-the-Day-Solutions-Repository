/*
Problem of the Day: Min Cost Climbing Stairs
Problem Description: https://www.geeksforgeeks.org/problems/min-cost-climbing-stairs/1
*/

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 2) return min(cost[0], cost[1]);
        
        int prev1 = cost[1];
        int prev2 = cost[0];

        for (int i = 2; i < n; ++i) {
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }
};
