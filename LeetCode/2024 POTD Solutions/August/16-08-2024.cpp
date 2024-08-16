/*
Problem of the Day: 624. Maximum Distance in Arrays
Problem Description: https://medium.com/@pradeepsooryavanshee1210/624-maximum-distance-in-arrays-leetcode-solution-6a0947c8f764
*/

class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int globalMin = arrays[0][0];
        int globalMax = arrays[0].back();
        int maxDistance = 0;

        for (int i = 1; i < arrays.size(); ++i)
        {
            int currentMin = arrays[i][0];
            int currentMax = arrays[i].back();

            maxDistance = max(maxDistance, abs(currentMax - globalMin));
            maxDistance = max(maxDistance, abs(currentMin - globalMax));

            globalMin = min(globalMin, currentMin);
            globalMax = max(globalMax, currentMax);
        }

        return maxDistance;
    }
};