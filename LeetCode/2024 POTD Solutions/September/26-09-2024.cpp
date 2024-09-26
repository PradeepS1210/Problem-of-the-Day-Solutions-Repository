/*
Problem of the Day: 729. My Calendar I
Problem Description: https://medium.com/@pradeepsooryavanshee1210/729-my-calendar-i-leetcode-solution-f86f6652a2d1
*/

class MyCalendar
{
private:
    vector<pair<int, int>> bookings;

public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        for (const auto &booking : bookings)
        {
            int bookedStart = booking.first;
            int bookedEnd = booking.second;

            if (start < bookedEnd && bookedStart < end)
            {
                return false;
            }
        }

        bookings.push_back({start, end});
        return true;
    }
};