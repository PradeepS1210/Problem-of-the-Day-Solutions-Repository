/*
Problem of the Day: Median of two sorted arrays
Asked in : AmazonD-E-Shaw
Problem Description: https://medium.com/@pradeepsooryavanshee1210/amazon-interview-question-median-of-two-sorted-arrays-geeksforgeeks-solution-98e9e3eb76e9
*/

class Solution
{
public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2)
    {
        int n1 = arr1.size();
        int n2 = arr2.size();
        vector<int> merged(n1 + n2);

        int i = 0, j = 0, k = 0;
        while (i < n1 && j < n2)
        {
            if (arr1[i] <= arr2[j])
            {
                merged[k++] = arr1[i++];
            }
            else
            {
                merged[k++] = arr2[j++];
            }
        }

        while (i < n1)
        {
            merged[k++] = arr1[i++];
        }
        while (j < n2)
        {
            merged[k++] = arr2[j++];
        }

        int totalLength = merged.size();
        if (totalLength % 2 == 1)
        {
            return merged[totalLength / 2];
        }
        else
        {
            int mid1 = totalLength / 2 - 1;
            int mid2 = totalLength / 2;
            return merged[mid1] + merged[mid2];
        }
    }
};