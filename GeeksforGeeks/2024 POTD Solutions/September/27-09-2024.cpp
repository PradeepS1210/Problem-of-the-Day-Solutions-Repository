/*
Asked in Flipkart, Amazon, Microsoft, Directi, Google
Problem of the Day: K Sized Subarray Maximum
Problem Description: https://medium.com/@pradeepsooryavanshee1210/k-sized-subarray-maximum-geeksforgeeks-solution-350adf44110a
*/

class Solution
{
public:
    vector<int> max_of_subarrays(int k, vector<int> &arr)
    {
        vector<int> result;

        deque<int> dq;

        for (int i = 0; i < arr.size(); ++i)
        {

            if (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }

            while (!dq.empty() && arr[dq.back()] <= arr[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1)
            {
                result.push_back(arr[dq.front()]);
            }
        }

        return result;
    }
};