/*
Asked in Zoho
Problem of the Day: Total count
Problem Description: https://medium.com/@pradeepsooryavanshee1210/total-count-geeksforgeeks-solution-b96711e15675
*/

class Solution {
public:
    int totalCount(int k, vector<int>& arr) {
        int total_steps = 0;
        for (int i = 0; i < arr.size(); ++i) {
            total_steps += (arr[i] + k - 1) / k;
        }
        return total_steps;
    }
};