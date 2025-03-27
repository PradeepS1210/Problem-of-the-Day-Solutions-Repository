/*
Problem of the Day: Repeating Ones
Problem Description: https://unstop.com/code/practice/261397
*/

#include <iostream>
#include <string>
using namespace std;

const int MODULO = 1000000007;

int main() {
    string str;
    cin >> str;
    
    long long result = 0;
    int count = 0;
    
    for (char ch : str) {
        if (ch == '1') {
            count++;
            result = (result + count) % MODULO;
        } else {
            count = 0;
        }
    }
    
    cout << result << endl;
    return 0;
}
