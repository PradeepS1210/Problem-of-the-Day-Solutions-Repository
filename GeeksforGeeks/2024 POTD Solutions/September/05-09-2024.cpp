/*
Asked in Flipkart, Morgan Stanley, Accolite, Amazon, Microsoft, D-E-Shaw, Ola Cabs, Payu, Visa, Intuit, Adobe, Cisco, Qualcomm, TCS
Problem of the Day: Missing in Array
Problem Description: https://medium.com/@pradeepsooryavanshee1210/missing-in-array-geeksforgeeks-solution-9af89650020d
*/

class Solution
{
public:
    int missingNumber(int n, vector<int> &arr)
    {
        int totalSum = n * (n + 1) / 2;

        int arraySum = 0;
        for (int num : arr)
        {
            arraySum += num;
        }

        return totalSum - arraySum;
    }
};
