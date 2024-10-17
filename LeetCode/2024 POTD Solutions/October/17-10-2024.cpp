/*
Problem of the Day: 670. Maximum Swap
Problem Description: https://medium.com/@pradeepsooryavanshee1210/670-maximum-swap-leetcode-solution-4b8c37ac2e66
*/

class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        
        vector<int> lastPos(10, -1);
        
        for (int i = 0; i < n; ++i) {
            lastPos[numStr[i] - '0'] = i;
        }
        
        for (int i = 0; i < n; ++i) {
            for (int d = 9; d > numStr[i] - '0'; --d) {
                if (lastPos[d] > i) {
                    swap(numStr[i], numStr[lastPos[d]]);
                    return stoi(numStr);
                }
            }
        }
        
        return num;
    }
};