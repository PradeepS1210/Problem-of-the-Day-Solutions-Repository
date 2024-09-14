/*
Asked in Paytm, VMWare, Amazon, Microsoft, Intuit
Problem of the Day: Alternate positive and negative numbers
Problem Description: https://medium.com/@pradeepsooryavanshee1210/alternate-positive-and-negative-numbers-geeksforgeeks-solution-7d06a2652c30
*/

class Solution
{
public:
    void rearrange(vector<int> &arr)
    {
        vector<int> pos, neg;

        for (int num : arr)
        {
            if (num >= 0)
                pos.push_back(num);
            else
                neg.push_back(num);
        }

        int i = 0, p = 0, n = 0;
        bool turnPos = true;

        while (p < pos.size() && n < neg.size())
        {
            if (turnPos)
            {
                arr[i++] = pos[p++];
            }
            else
            {
                arr[i++] = neg[n++];
            }
            turnPos = !turnPos;
            e
        }

        while (p < pos.size())
        {
            arr[i++] = pos[p++];
        }

        while (n < neg.size())
        {
            arr[i++] = neg[n++];
        }
    }
};