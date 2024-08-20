/*
Problem of the Day: 1140. Stone Game II
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1140-stone-game-ii-leetcode-solution-b7f3014e0797
*/

class Solution
{
public:
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        vector<int> suffixSum(n);
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            suffixSum[i] = piles[i] + suffixSum[i + 1];
        }

        function<int(int, int)> helper = [&](int i, int M)
        {
            if (i == n)
                return 0;
            if (2 * M >= n - i)
                return suffixSum[i];
            if (dp[i][M] != -1)
                return dp[i][M];

            int minOppStones = INT_MAX;
            for (int X = 1; X <= 2 * M; ++X)
            {
                minOppStones = min(minOppStones, helper(i + X, max(M, X)));
            }

            dp[i][M] = suffixSum[i] - minOppStones;
            return dp[i][M];
        };

        return helper(0, 1);
    }
};