/*
Problem of the Day: Union of Arrays with Duplicates
Problem Description: https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1
*/

class Solution {
public:
    int findUnion(vector<int>& a, vector<int>& b) {
        set<int> unionSet;

        for (int num : a) {
            unionSet.insert(num);
        }

        for (int num : b) {
            unionSet.insert(num);
        }

        return unionSet.size();
    }
};