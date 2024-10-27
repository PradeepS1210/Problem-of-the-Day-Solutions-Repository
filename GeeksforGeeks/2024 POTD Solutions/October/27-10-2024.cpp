/*
Problem of the Day: Triplet Family
Problem Description: https://medium.com/@pradeepsooryavanshee1210/triplet-family-geeksforgeeks-solution-f96174e1b6f8
*/

class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        vector<int> li(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {
                int sum = arr[i] + arr[j];

                if (find(li.begin(), li.end(), sum) != li.end()) {
                    return true;
                }
            }
        }
        return false;
    }
};
