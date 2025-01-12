/*
Problem of the Day: Panel's bar
Problem Description: https://unstop.com/code/practice/261660
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangle(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    int n = heights.size();
    
    for (int i = 0; i <= n; i++) {
        while (!s.empty() && (i == n || heights[s.top()] >= heights[i])) {
            int height = heights[s.top()];
            s.pop();
            int width;
            if (s.empty()) {
                width = i;
            } else {
                width = i - s.top() - 1;
            }
            maxArea = max(maxArea, height * width);
        }
        s.push(i);
    }
    return maxArea;
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    cout << largestRectangle(heights) << endl;
    return 0;
}
