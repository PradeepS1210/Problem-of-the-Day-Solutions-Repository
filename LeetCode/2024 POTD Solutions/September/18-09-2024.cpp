/*
Problem of the Day: 179. Largest Number
Problem Description: https://medium.com/@pradeepsooryavanshee1210/179-largest-number-leetcode-solution-b0a4b1432bc8
*/

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> strNums;
        for (int num : nums)
        {
            strNums.push_back(to_string(num));
        }

        sort(strNums.begin(), strNums.end(), [](const string &a, const string &b)
             { return a + b > b + a; });

        if (strNums[0] == "0")
        {
            return "0";
        }

        string result;
        for (const string &str : strNums)
        {
            result += str;
        }

        return result;
    }
};