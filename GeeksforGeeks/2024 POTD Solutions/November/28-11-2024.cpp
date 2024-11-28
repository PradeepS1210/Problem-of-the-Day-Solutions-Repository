/*
Problem of the Day: Implement Atoi
Problem Description: https://medium.com/@pradeepsooryavanshee1210/implement-atoi-geeksforgeeks-solution-34aa34ae565a
*/

class Solution {
public:
    int myAtoi(char *s) {
        int i = 0;
        int sign = 1;
        long result = 0;

        while (s[i] == ' ') {
            i++;
        }

        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (s[i] >= '0' && s[i] <= '9') {
            result = result * 10 + (s[i] - '0');

            if (result * sign > INT_MAX) {
                return INT_MAX;
            }
            if (result * sign < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return (int)(result * sign);
    }
};