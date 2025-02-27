/*
Problem of the Day: Get Min from Stack
Problem Description: https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1
*/

class Solution {
  stack<int> mainStack;
  stack<int> minStack;

  public:
    Solution() {
        minStack.push(INT_MAX);
    }

    void push(int x) {
        mainStack.push(x);
        if (x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (!mainStack.empty()) {
            int topElement = mainStack.top();
            mainStack.pop();
            if (topElement == minStack.top()) {
                minStack.pop();
            }
        }
    }

    int peek() {
        if (mainStack.empty()) {
            return -1;
        }
        return mainStack.top();
    }

    int getMin() {
        if (mainStack.empty()) {
            return -1;
        }
        return minStack.top();
    }
};
