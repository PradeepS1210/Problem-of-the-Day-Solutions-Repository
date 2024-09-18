/*
Asked in Flipkart, Amazon, Microsoft, OYO Rooms, Snapdeal, Oracle, Walmart, Adobe, Google, Yatra.com
Problem of the Day: Parenthesis Checker
Problem Description: https://medium.com/@pradeepsooryavanshee1210/parenthesis-checker-geeksforgeeks-solution-fa06641ed020
*/

class Solution
{
public:
    bool ispar(string x)
    {
        stack<char> st;

        for (char ch : x)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else
            {
                if (st.empty())
                    return false;

                char top = st.top();
                st.pop();

                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '['))
                {
                    return false;
                }
            }
        }

        return st.empty();
    }
};