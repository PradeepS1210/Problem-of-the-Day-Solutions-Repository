/*
Problem of the Day: 2419. Longest Subarray With Maximum Bitwise AND
Problem Description: https://medium.com/@pradeepsooryavanshee1210/2419-longest-subarray-with-maximum-bitwise-and-leetcode-solution-6f175f686ce0
*/

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int maxElement = *max_element(nums.begin(), nums.end());
        int maxLength = 0, currentLength = 0;

        for (int num : nums)
        {
            if (num == maxElement)
            {
                currentLength++;
                maxLength = max(maxLength, currentLength);
            }
            else
            {
                currentLength = 0;
            }
        }

        return maxLength;
    }
};