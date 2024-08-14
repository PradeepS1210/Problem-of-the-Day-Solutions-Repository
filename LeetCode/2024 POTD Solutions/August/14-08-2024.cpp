/*
Problem of the Day: 719. Find K-th Smallest Pair Distance
Problem Description: https://medium.com/@pradeepsooryavanshee1210/719-find-k-th-smallest-pair-distance-leetcode-solution-9ed613a0f302
*/

class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.back() - nums.front();

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (countPairs(nums, mid) < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }

private:
    int countPairs(const vector<int> &nums, int dist)
    {
        int count = 0;
        int n = nums.size();
        int j = 0;

        for (int i = 0; i < n; ++i)
        {
            while (j < n && nums[j] - nums[i] <= dist)
            {
                ++j;
            }
            count += (j - i - 1);
        }

        return count;
    }
};