/*
Problem of the Day: k largest elements
Problem Description: https://www.geeksforgeeks.org/problems/k-largest-elements4206/1
*/

class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int i = 0; i < arr.size(); ++i) {
            minHeap.push(arr[i]);
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        vector<int> result;
        while(!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        
        sort(result.begin(), result.end(), greater<int>());
        
        return result;
    }
};
