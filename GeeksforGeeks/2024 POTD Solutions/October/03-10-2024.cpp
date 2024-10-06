/*
Problem of the Day: Majority Vote
Problem Description: https://medium.com/@pradeepsooryavanshee1210/majority-vote-geeksforgeeks-solution-cb7d4c7dd74b
*/

class Solution {
public:
    vector<int> findMajority(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        if (n == 0) return result;

        unordered_map<int, int> counts;

        for (int num : nums) {
            counts[num]++;
        }

        for (const auto& entry : counts) {
            if (entry.second > n / 3) {
                result.push_back(entry.first);
            }
        }

        if (result.empty()) {
            return {-1};
        }

        sort(result.begin(), result.end());

        return result;
    }
};