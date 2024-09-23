/*
Asked in Amazon, Samsung, D-E-Shaw, Goldman Sachs, MAQ Software
Problem of the Day: Missing And Repeating
Problem Description: https://medium.com/@pradeepsooryavanshee1210/missing-and-repeating-geeksforgeeks-solution-02a1f7468894
*/

class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        int n = arr.size();

        long long sum_expected = (n * (n + 1LL)) / 2;
        long long sumOfSquares_expected = (n * (n + 1LL) * (2 * n + 1LL)) / 6;

        long long sum_actual = 0;
        long long sumOfSquares_actual = 0;

        for (int i = 0; i < n; i++)
        {
            sum_actual += arr[i];
            sumOfSquares_actual += (long long)arr[i] * arr[i];
        }

        long long sum_diff = sum_expected - sum_actual;
        long long sumOfSquares_diff = sumOfSquares_expected - sumOfSquares_actual;

        long long sum_plus = sumOfSquares_diff / sum_diff;

        int x = (sum_diff + sum_plus) / 2;
        int y = sum_plus - x;

        return {y, x};
    }
};