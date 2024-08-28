/*
Asked in Oracle, Zycus
Problem of the Day: Sorting Elements of an Array by Frequency
Problem Description: https://medium.com/@pradeepsooryavanshee1210/sorting-elements-of-an-array-by-frequency-geeksforgeeks-solution-5c031cc658a2
*/

class Solution
{
public:
    std::vector<int> sortByFreq(std::vector<int> &arr)
    {
        std::unordered_map<int, int> freqMap;
        for (int num : arr)
        {
            freqMap[num]++;
        }

        std::map<int, std::vector<int>, std::greater<int>> freqBuckets;
        for (auto it = freqMap.begin(); it != freqMap.end(); ++it)
        {
            freqBuckets[it->second].push_back(it->first);
        }

        std::vector<int> result;
        for (auto it = freqBuckets.begin(); it != freqBuckets.end(); ++it)
        {
            std::vector<int> &nums = it->second;
            std::sort(nums.begin(), nums.end());
            for (int num : nums)
            {
                result.insert(result.end(), it->first, num);
            }
        }

        return result;
    }
};