/*
Problem of the Day: 564. Find the Closest Palindrome
Problem Description: https://medium.com/@pradeepsooryavanshee1210/564-find-the-closest-palindrome-leetcode-solution-d1006ed6ad71
*/

class Solution
{
public:
    string nearestPalindromic(string n)
    {
        int len = n.length();
        long originalNumber = stol(n);
        set<long> candidates;

        candidates.insert(pow(10, len) + 1);
        candidates.insert(pow(10, len - 1) - 1);

        long prefix = stol(n.substr(0, (len + 1) / 2));
        for (int i = -1; i <= 1; ++i)
        {
            string p = to_string(prefix + i);
            string candidate = p + string(p.rbegin() + (len % 2), p.rend());
            candidates.insert(stol(candidate));
        }

        candidates.erase(originalNumber);

        long closest = -1;
        for (long candidate : candidates)
        {
            if (closest == -1 ||
                abs(candidate - originalNumber) < abs(closest - originalNumber) ||
                (abs(candidate - originalNumber) == abs(closest - originalNumber) && candidate < closest))
            {
                closest = candidate;
            }
        }

        return to_string(closest);
    }
};