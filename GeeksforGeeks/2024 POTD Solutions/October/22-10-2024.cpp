/*
Problem of the Day: Sub-arrays with equal number of occurences
Problem Description: https://medium.com/@pradeepsooryavanshee1210/sub-arrays-with-equal-number-of-occurences-geeksforgeeks-solution-fce87fc4cd44
*/

class Solution {
public:
    int sameOccurrence(std::vector<int>& arr, int x, int y) {
        std::unordered_map<int, int> freq_map;
        freq_map[0] = 1;
        int diff = 0;
        int count_x = 0;
        int count_y = 0;
        int result = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == x) count_x++;
            if (arr[i] == y) count_y++;
            
            diff = count_x - count_y;
            
            if (freq_map.find(diff) != freq_map.end()) {
                result += freq_map[diff];
            }
            
            freq_map[diff]++;
        }
        
        return result;
    }
};
