/*
Problem of the Day: 1942. The Number of the Smallest Unoccupied Chair
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1942-the-number-of-the-smallest-unoccupied-chair-leetcode-solution-c43c6a3ec7b9
*/

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        vector<array<int, 3>> events;
        
        for (int i = 0; i < n; ++i) {
            events.push_back({times[i][0], times[i][1], i});
        }
        
        sort(events.begin(), events.end());
        
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        
        for (int i = 0; i < n; ++i) {
            availableChairs.push(i);
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> occupiedChairs;
        
        for (const auto& event : events) {
            int arrival = event[0], departure = event[1], friendId = event[2];
            
            while (!occupiedChairs.empty() && occupiedChairs.top().first <= arrival) {
                availableChairs.push(occupiedChairs.top().second);
                occupiedChairs.pop();
            }
            
            int chair = availableChairs.top();
            availableChairs.pop();
            
            if (friendId == targetFriend) {
                return chair;
            }
            
            occupiedChairs.push({departure, chair});
        }
        
        return -1;
    }
};