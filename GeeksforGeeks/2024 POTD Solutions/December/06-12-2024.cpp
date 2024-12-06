/*
Problem of the Day: Find H-Index
Problem Description: https://medium.com/@pradeepsooryavanshee1210/find-h-index-geeksforgeeks-solution-b97cb771812f
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        
        int n = citations.size();
        int hIndex = 0;

        for (int i = 0; i < n; i++) {
            int h = n - i;
            if (citations[i] >= h) {
                hIndex = h;
                break;
            }
        }
        return hIndex;
    }
};