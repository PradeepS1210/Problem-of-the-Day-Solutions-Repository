/*
Problem of the Day: 1652. Defuse the Bomb
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1652-defuse-the-bomb-geeksforgeeks-solution-b38192b7432d
*/

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);

        if (k == 0) {
            return result;
        }

        for (int i = 0; i < n; i++) {
            int sum = 0;

            if (k > 0) {
                for (int j = 1; j <= k; j++) {
                    sum += code[(i + j) % n];
                }
            } else {
                for (int j = 1; j <= abs(k); j++) {
                    sum += code[(i - j + n) % n];
                }
            }

            result[i] = sum;
        }

        return result;
    }
};