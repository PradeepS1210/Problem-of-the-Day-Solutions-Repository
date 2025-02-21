/*
Problem of the Day: Homogenous Substring
Problem Description: https://unstop.com/code/practice/261429
*/

#include <iostream>
#include <string>

using namespace std;

const int MOD = 1e9 + 7;

int countHomogeneousSubstrings(const string& str) {
    long long count = 0;
    int n = str.size();
    
    for (int i = 0; i < n; ++i) {
        int length = 1;
        while (i + 1 < n && str[i] == str[i + 1]) {
            ++length;
            ++i;
        }
        count = (count + (long long)length * (length + 1) / 2) % MOD;
    }
    
    return count;
}

int main() {
    string str;
    cin >> str;
    
    int result = countHomogeneousSubstrings(str);
    cout << result << endl;
    
    return 0;
}
