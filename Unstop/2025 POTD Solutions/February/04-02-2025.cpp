/*
Problem of the Day: Two-Digit Max Number
Problem Description: https://unstop.com/code/practice/519321
*/

#include <bits/stdc++.h>
using namespace std;

int largestPossibleNumber(vector<int> &arr, int n) {
    set<int> twoDigitNumbers;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 10 && arr[i] < 100) {
            twoDigitNumbers.insert(arr[i]);
        }
    }
    
    if (twoDigitNumbers.size() < 2) {
        return 0;
    }
    
    auto it = twoDigitNumbers.begin();
    int firstSmallest = *it;
    it++;
    int secondSmallest = *it;
    
    vector<int> digits;
    digits.push_back(firstSmallest / 10);
    digits.push_back(firstSmallest % 10);
    digits.push_back(secondSmallest / 10);
    digits.push_back(secondSmallest % 10);
    
    sort(digits.rbegin(), digits.rend());
    
    int largestNumber = 0;
    for (int digit : digits) {
        largestNumber = largestNumber * 10 + digit;
    }
    
    return largestNumber;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int result = largestPossibleNumber(arr, n);
    cout << result << endl;
    
    return 0;
}
