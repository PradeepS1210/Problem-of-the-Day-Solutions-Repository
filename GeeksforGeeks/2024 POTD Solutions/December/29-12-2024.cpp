/*
Problem of the Day: Intersection of Two arrays with Duplicate Elements
Problem Description: https://www.geeksforgeeks.org/problems/intersection-of-two-arrays-with-duplicate-elements/1
*/

class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        unordered_map<int, int> freqMap;
        for (int num : a) {
            freqMap[num]++;
        }

        vector<int> result;
        for (int num : b) {
            if (freqMap[num] > 0) {
                result.push_back(num);
                freqMap[num] = 0;
            }
        }

        return result;
    }
};