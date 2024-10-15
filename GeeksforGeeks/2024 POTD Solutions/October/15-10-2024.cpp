/*
Problem of the Day: Subarray range with given sum
Problem Description: https://medium.com/@pradeepsooryavanshee1210/subarray-range-with-given-sum-geeksforgeeks-solution-b5c1fe852984
*/

class Solution {
  public:
    int subArraySum(vector<int>& arr, int tar) {
        unordered_map<long long, int> prefixSumCount;
        prefixSumCount[0] = 1;
        
        long long currentSum = 0;
        int count = 0;
        
        for(auto num : arr){
            currentSum += num;
            
            if(prefixSumCount.find(currentSum - tar) != prefixSumCount.end()){
                count += prefixSumCount[currentSum - tar];
            }
            
            prefixSumCount[currentSum]++;
        }
        
        return count;
    }
};