/*
Asked in Accolite, Amazon, Microsoft
Problem of the Day: Count distinct elements in every window
Problem Description: https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1
*/

class Solution {
public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int> result;
        unordered_map<int, int> freq;
        int distinctCount = 0;

        for (int i = 0; i < k; i++) {
            if (freq[arr[i]] == 0) {
                distinctCount++;
            }
            freq[arr[i]]++;
        }
        result.push_back(distinctCount);

        for (int i = k; i < arr.size(); i++) {
            if (freq[arr[i - k]] == 1) {
                distinctCount--;
            }
            freq[arr[i - k]]--;

            if (freq[arr[i]] == 0) {
                distinctCount++;
            }
            freq[arr[i]]++;
            
            result.push_back(distinctCount);
        }

        return result;
    }
};