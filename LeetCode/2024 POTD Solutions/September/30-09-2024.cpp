/*
Problem of the Day: 1381. Design a Stack With Increment Operation 
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1381-design-a-stack-with-increment-operation-leetcode-solution-c3791c3c642f
*/

class CustomStack {
private:
    vector<int> stack;
    int maxSize;

public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
        }
    }
    
    int pop() {
        if (stack.empty()) {
            return -1;
        }
        int topElement = stack.back();
        stack.pop_back();
        return topElement;
    }
    
    void increment(int k, int val) {
        int limit = min(k, (int)stack.size());
        for (int i = 0; i < limit; ++i) {
            stack[i] += val;
        }
    }
};