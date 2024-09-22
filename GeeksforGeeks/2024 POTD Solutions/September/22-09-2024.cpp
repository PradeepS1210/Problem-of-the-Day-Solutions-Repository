/*
Asked in Accolite, Amazon, Microsoft, MakeMyTrip
Problem of the Day: Longest Prefix Suffix
Problem Description: https://medium.com/@pradeepsooryavanshee1210/longest-prefix-suffix-geeksforgeeks-solution-ee26745c0239
*/

class Solution
{
public:
    int lps(string str)
    {
        int n = str.size();
        vector<int> lps(n, 0);
        int len = 0;
        int i = 1;

        while (i < n)
        {
            if (str[i] == str[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps[n - 1];
    }
};