/*
Asked in Amazon
Problem of the Day: Remove duplicates in array
Problem Description: https://medium.com/@pradeepsooryavanshee1210/remove-duplicates-in-array-geeksforgeeks-solution-28a37ede69fe
*/

class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        unordered_set<int> seen;
        vector<int> result;
        
        for (int num : arr) {
            if (seen.find(num) == seen.end()) {
                seen.insert(num);
                result.push_back(num);
            }
        }
        
        return result;
    }
};
