/*
Problem of the Day: 539. Minimum Time Difference
Problem Description: https://medium.com/@pradeepsooryavanshee1210/539-minimum-time-difference-leetcode-solution-b73ec19b3963
*/

class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        vector<int> minutes;
        for (const string &time : timePoints)
        {
            int hours = stoi(time.substr(0, 2));
            int mins = stoi(time.substr(3, 2));
            minutes.push_back(hours * 60 + mins);
        }

        sort(minutes.begin(), minutes.end());

        int minDiff = INT_MAX;

        for (int i = 1; i < minutes.size(); ++i)
        {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }

        int circularDiff = (24 * 60 - minutes.back()) + minutes[0];
        minDiff = min(minDiff, circularDiff);

        return minDiff;
    }
};