/*
Asked in Amazon, Microsoft, Facebook
Problem of the Day: Add Binary Strings
Problem Description: https://medium.com/@pradeepsooryavanshee1210/add-binary-strings-geeksforgeeks-solution-8bd24ae94e8d
*/

class Solution {
public:
    string addBinary(string& s1, string& s2) {
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int carry = 0;
        string result = "";
        
        while (i >= 0 || j >= 0 || carry > 0) {
            int bit1 = (i >= 0) ? s1[i] - '0' : 0;
            int bit2 = (j >= 0) ? s2[j] - '0' : 0;
            int sum = bit1 + bit2 + carry;
            
            result += (sum % 2) + '0';
            carry = sum / 2;
            
            i--;
            j--;
        }
        
        reverse(result.begin(), result.end());
        
        auto pos = result.find_first_not_of('0');
        return (pos == string::npos) ? "0" : result.substr(pos);
    }
};