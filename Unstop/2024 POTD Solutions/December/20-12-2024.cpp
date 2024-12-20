/*
Problem of the Day: Shop and Candies
Problem Description: https://unstop.com/code/practice/301956
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> prices(N);
    for (int i = 0; i < N; i++) {
        cin >> prices[i];
    }
    
    int M;
    cin >> M;
    
    vector<int> money(M);
    for (int i = 0; i < M; i++) {
        cin >> money[i];
    }
    
    sort(prices.begin(), prices.end());
    
    vector<int> results(M);
    for (int i = 0; i < M; i++) {
        int options = upper_bound(prices.begin(), prices.end(), money[i]) - prices.begin();
        results[i] = options;
    }
    
    for (int result : results) {
        cout << result << endl;
    }
    
    return 0;
}
