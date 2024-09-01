/*
Asked in Amazon
Problem of the Day: Max sum path in two arrays
Problem Description: https://medium.com/@pradeepsooryavanshee1210/max-sum-path-in-two-arrays-geeksforgeeks-solution-f4c272cf463d
*/

class Solution
{
public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2)
    {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int i = 0, j = 0;
        int sum1 = 0, sum2 = 0;
        int result = 0;

        while (i < n1 && j < n2)
        {
            if (arr1[i] < arr2[j])
            {
                sum1 += arr1[i++];
            }
            else if (arr1[i] > arr2[j])
            {
                sum2 += arr2[j++];
            }
            else
            {
                result += max(sum1, sum2) + arr1[i];
                sum1 = sum2 = 0;
                i++;
                j++;
            }
        }

        while (i < n1)
            sum1 += arr1[i++];
        while (j < n2)
            sum2 += arr2[j++];

        result += max(sum1, sum2);

        return result;
    }
};