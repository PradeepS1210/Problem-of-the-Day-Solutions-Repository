/*
Problem of the Day: 1106. Parsing A Boolean Expression
Problem Description: https://medium.com/@pradeepsooryavanshee1210/1106-parsing-a-boolean-expression-leetcode-solution-b0c630cd751d
*/

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;
        
        for (char c : expression) {
            if (c == ',' || c == '(') {
                continue;
            } else if (c == 't' || c == 'f' || c == '!' || c == '&' || c == '|') {
                stk.push(c);
            } else if (c == ')') {
                vector<char> subExpr;
                
                while (stk.top() != '!' && stk.top() != '&' && stk.top() != '|') {
                    subExpr.push_back(stk.top());
                    stk.pop();
                }
                
                char operatorChar = stk.top();
                stk.pop();
                
                char result;
                if (operatorChar == '&') {
                    result = 't';
                    for (char ch : subExpr) {
                        if (ch == 'f') {
                            result = 'f';
                            break;
                        }
                    }
                } else if (operatorChar == '|') {
                    result = 'f';
                    for (char ch : subExpr) {
                        if (ch == 't') {
                            result = 't';
                            break;
                        }
                    }
                } else if (operatorChar == '!') {
                    result = (subExpr[0] == 't') ? 'f' : 't';
                }
                
                stk.push(result);
            }
        }
        
        return stk.top() == 't';
    }
};
