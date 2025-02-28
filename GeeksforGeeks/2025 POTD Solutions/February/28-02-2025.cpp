/*
Problem of the Day: Evaluation of Postfix Expression
Problem Description: https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1
*/

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        stack<int> stack;
        for (const string& token : arr) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();
                if (token == "+") stack.push(a + b);
                else if (token == "-") stack.push(a - b);
                else if (token == "*") stack.push(a * b);
                else if (token == "/") stack.push(a / b);
            } else {
                stack.push(stoi(token));
            }
        }
        return stack.top();
    }
};
