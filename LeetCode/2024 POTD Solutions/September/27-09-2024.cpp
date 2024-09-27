/*
Problem of the Day: 731. My Calendar II
Problem Description: https://medium.com/@pradeepsooryavanshee1210/731-my-calendar-ii-leetcode-solution-521a3ecede9d
*/

class MyCalendarTwo
{
private:
    std::vector<std::pair<int, int>> bookings;
    std::vector<std::pair<int, int>> overlaps;

public:
    MyCalendarTwo()
    {
    }

    bool book(int start, int end)
    {
        for (const auto &interval : overlaps)
        {
            int overlap_start = std::max(start, interval.first);
            int overlap_end = std::min(end, interval.second);
            if (overlap_start < overlap_end)
            {
                return false;
            }
        }

        for (const auto &interval : bookings)
        {
            int overlap_start = std::max(start, interval.first);
            int overlap_end = std::min(end, interval.second);
            if (overlap_start < overlap_end)
            {
                overlaps.emplace_back(overlap_start, overlap_end);
            }
        }

        bookings.emplace_back(start, end);
        return true;
    }
};