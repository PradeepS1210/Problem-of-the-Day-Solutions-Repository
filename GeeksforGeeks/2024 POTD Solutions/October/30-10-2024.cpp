/*
Asked in Adobe
Problem of the Day: Pairs with difference k
Problem Description: https://medium.com/@pradeepsooryavanshee1210/pairs-with-difference-k-geeksforgeeks-solution-89a035eec7b7
*/

class Solution {
  public:
    int countPairsWithDiffK(vector<int>& arr, int k) {
        unordered_map<int, int> numCount;
        int count = 0;

        for (int num : arr) {
            numCount[num]++;
        }

        for (auto& pair : numCount) {
            int num = pair.first;

            if (k > 0 && numCount.count(num + k)) {
                count += pair.second * numCount[num + k];
            }
            
            else if (k == 0 && pair.second > 1) {
                count += (pair.second * (pair.second - 1)) / 2;
            }
        }
        
        return count;
    }
};
