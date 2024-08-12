/*
Problem of the Day: 703. Kth Largest Element in a Stream
Problem Description: https://medium.com/@pradeepsooryavanshee1210/703-kth-largest-element-in-a-stream-leetcode-solution-b3d7c3afa63a
*/

class KthLargest
{
private:
    priority_queue<int, vector<int>, std::greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for (int num : nums)
        {
            add(num);
        }
    }

    int add(int val)
    {
        minHeap.push(val);
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
        return minHeap.top();
    }
};