/*
Problem of the Day: Find median in a stream
Problem Description: https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1
*/

class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double> medians;
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : arr) {
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }

            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            if (maxHeap.size() == minHeap.size()) {
                medians.push_back((maxHeap.top() + minHeap.top()) / 2.0);
            } else {
                medians.push_back(maxHeap.top());
            }
        }

        return medians;
    }
};
