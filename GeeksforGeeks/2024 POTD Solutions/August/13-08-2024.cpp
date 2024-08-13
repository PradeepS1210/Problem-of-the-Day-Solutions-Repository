/*
Asked in VMWare, Flipkart, Accolite, Amazon, and Microsoft
Problem of the Day: Square root of a number
Problem Description: https://medium.com/@pradeepsooryavanshee1210/square-root-of-a-number-geeksforgeeks-solution-b06841df0432
*/

class Solution
{
public:
    long long int floorSqrt(long long int n)
    {
        if (n == 0 || n == 1)
            return n;

        long long int low = 1, high = n, ans = 0;

        while (low <= high)
        {
            long long int mid = low + (high - low) / 2;

            if (mid * mid == n)
            {
                return mid;
            }
            else if (mid * mid < n)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};