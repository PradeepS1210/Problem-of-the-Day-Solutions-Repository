/*
Problem of the Day: Buy Property 2
Problem Description: https://medium.com/@pradeepsooryavanshee1210/buy-property-2-unstop-solution-fc205d8f862f
*/

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int totalProfit = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1]) {
            totalProfit += prices[i] - prices[i - 1];
        }
    }
    return totalProfit;
}

int main() {
    int N;
    cin >> N;
    vector<int> prices(N);
    
    for (int i = 0; i < N; i++) {
        cin >> prices[i];
    }

    cout << maxProfit(prices) << endl;
    return 0;
}