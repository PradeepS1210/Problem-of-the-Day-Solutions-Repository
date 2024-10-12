/*
Problem of the Day: 2406. Divide Intervals Into Minimum Number of Groups
Problem Description: https://medium.com/@pradeepsooryavanshee1210/2406-divide-intervals-into-minimum-number-of-groups-leetcode-solution-7e7fc7797b25
*/

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int, int>> events;
        events.reserve(intervals.size() * 2);
        
        for(const auto& interval : intervals){
            int start = interval[0];
            int end = interval[1];
            events.emplace_back(start, 0);
            events.emplace_back(end, 1);
        }
        
        sort(events.begin(), events.end(), [&](const pair<int,int>& a, const pair<int,int>& b) -> bool {
            if(a.first != b.first){
                return a.first < b.first;
            }
            return a.second < b.second;
        });
        
        int active = 0;
        int max_active = 0;
        
        for(const auto& event : events){
            if(event.second == 0){
                active +=1;
                if(active > max_active){
                    max_active = active;
                }
            }
            else{
                active -=1;
            }
        }
        
        return max_active;
    }
};