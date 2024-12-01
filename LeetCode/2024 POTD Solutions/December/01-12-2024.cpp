/*
Problem fo the Day: 1346. Check If N and Its Double Exist
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1346-check-if-n-and-its-double-exist-leetcode-solution-623429e1f686
*/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> seen;
        for (int num : arr) {
            if (seen.count(2 * num) || (num % 2 == 0 && seen.count(num / 2))) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};