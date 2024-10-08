/*
Problem of the Day: Validate an IP Address
Problem Description: https://medium.com/@pradeepsooryavanshee1210/validate-an-ip-address-geeksforgeeks-solution-problem-of-the-day-ef32ce041338
Asked in Zoho, Amazon, Microsoft and Qualcomm
*/

class Solution
{
public:
    int isValid(string s)
    {
        int dotCount = 0;
        for (char c : s)
        {
            if (c == '.')
                dotCount++;
        }

        if (dotCount != 3)
            return 0;

        stringstream ss(s);
        string segment;
        while (getline(ss, segment, '.'))
        {
            if (segment.empty())
                return 0;

            if (segment.size() > 1 && segment[0] == '0')
                return 0;

            for (char c : segment)
            {
                if (!isdigit(c))
                    return 0;
            }

            int num = stoi(segment);
            if (num < 0 || num > 255)
                return 0;
        }

        return 1;
    }
};