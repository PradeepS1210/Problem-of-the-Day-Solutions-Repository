/*
Problem of the Day: Longest Bounded-Difference Subarray
Problem Description: https://www.geeksforgeeks.org/problems/longest-bounded-difference-subarray/1
*/

class Solution {
    public:
        vector<int> longestSubarray(vector<int>& arr, int x) {
            int n = arr.size();
            deque<int> maxDeque, minDeque;
            int left = 0;
            int maxLength = 0;
            int startIndex = 0;
    
            for (int right = 0; right < n; ++right) {
                while (!maxDeque.empty() && arr[maxDeque.back()] <= arr[right]) {
                    maxDeque.pop_back();
                }
                maxDeque.push_back(right);
    
                while (!minDeque.empty() && arr[minDeque.back()] >= arr[right]) {
                    minDeque.pop_back();
                }
                minDeque.push_back(right);
    
                while (arr[maxDeque.front()] - arr[minDeque.front()] > x) {
                    if (maxDeque.front() == left) {
                        maxDeque.pop_front();
                    }
                    if (minDeque.front() == left) {
                        minDeque.pop_front();
                    }
                    ++left;
                }
    
                if (right - left + 1 > maxLength) {
                    maxLength = right - left + 1;
                    startIndex = left;
                }
            }
    
            return vector<int>(arr.begin() + startIndex, arr.begin() + startIndex + maxLength);
        }
    };