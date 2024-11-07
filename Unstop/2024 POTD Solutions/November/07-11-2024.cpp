/*
Problem of the Day: Excel value of product length
Problem Description: https://medium.com/@pradeepsooryavanshee1210/excel-value-of-product-length-unstop-solution-9e6a9759c9e1
*/

#include <bits/stdc++.h>
using namespace std;

string convertToExcelColumn(int n) {
    string result = "";
    while (n > 0) {
        n--;
        result = char('A' + (n % 26)) + result;
        n /= 26;
    }
    return result;
}

string maxProductExcelColumnName(const vector<string>& words) {
    int n = words.size();
    vector<int> bitmasks(n, 0);
    
    for (int i = 0; i < n; ++i) {
        for (char c : words[i]) {
            bitmasks[i] |= (1 << (c - 'a'));
        }
    }
    
    int maxProduct = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((bitmasks[i] & bitmasks[j]) == 0) {
                int product = words[i].length() * words[j].length();
                maxProduct = max(maxProduct, product);
            }
        }
    }
    
    if (maxProduct == 0) {
        return "0";
    }
    
    return convertToExcelColumn(maxProduct);
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }
    
    cout << maxProductExcelColumnName(words) << endl;
    return 0;
}