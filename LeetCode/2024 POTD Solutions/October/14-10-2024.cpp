/*
Problem of the Day: 2530. Maximal Score After Applying K Operations
Problem Description: https://medium.com/@pradeepsooryavanshee1210/2530-maximal-score-after-applying-k-operations-leetcode-solution-3fdf1dbe6d24
*/

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;

        for (int num : nums) {
            maxHeap.push(num);
        }

        long long score = 0;

        for (int i = 0; i < k; ++i) {
            int largest = maxHeap.top();
            maxHeap.pop();

            score += largest;

            int newVal = (largest + 2) / 3;
            maxHeap.push(newVal);
        }

        return score;
    }
};