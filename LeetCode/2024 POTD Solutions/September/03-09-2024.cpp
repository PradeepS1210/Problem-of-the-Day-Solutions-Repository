/*
Problem of the Day: 1945. Sum of Digits of String After Convert
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1945-sum-of-digits-of-string-after-convert-leetcode-solutions-15bc18a863c3
*/

class Solution
{
public:
    int getLucky(string s, int k)
    {
        string numericRepresentation = "";
        for (char c : s)
        {
            int position = c - 'a' + 1;
            numericRepresentation += to_string(position);
        }

        int result = 0;
        while (k--)
        {
            result = 0;
            for (char digit : numericRepresentation)
            {
                result += digit - '0';
            }
            numericRepresentation = to_string(result);
        }

        return result;
    }
};