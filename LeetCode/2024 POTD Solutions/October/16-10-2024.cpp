/*
Problem of the Day: 1405. Longest Happy String
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1405-longest-happy-string-leetcode-solution-f052937eaf4b
*/

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> maxHeap;
        
        if (a > 0) maxHeap.push({a, 'a'});
        if (b > 0) maxHeap.push({b, 'b'});
        if (c > 0) maxHeap.push({c, 'c'});
        
        string result = "";
        
        while (!maxHeap.empty()) {
            auto [count1, char1] = maxHeap.top();
            maxHeap.pop();
            
            if (result.size() >= 2 && result[result.size() - 1] == char1 && result[result.size() - 2] == char1) {
                if (maxHeap.empty()) {
                    break;
                }
                
                auto [count2, char2] = maxHeap.top();
                maxHeap.pop();
                
                result += char2;
                
                if (count2 - 1 > 0) {
                    maxHeap.push({count2 - 1, char2});
                }
                
                maxHeap.push({count1, char1});
                
            } else {
                result += char1;
                
                if (count1 - 1 > 0) {
                    maxHeap.push({count1 - 1, char1});
                }
            }
        }
        
        return result;
    }
};