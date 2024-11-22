/*
Asked in Bloomberg, Facebook, Intel, Infosys, Zoho, Morgan Stanley, Amazon, Microsoft, Samsung, Yahoo, PayPal, Nvidia, Oracle, Visa, Walmart, Goldman Sachs, TCS, Adobe, Google, IBM, Accenture, Apple, Uber
Problem of the Day: Stock Buy and Sell — Max one Transaction Allowed
Problem Description: https://medium.com/@pradeepsooryavanshee1210/stock-buy-and-sell-max-one-transaction-allowed-geeksforgeeks-solution-81202398b398
*/

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int n = prices.size();
        if (n < 2) return 0;

        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < n; i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                int profit = prices[i] - minPrice;
                maxProfit = max(maxProfit, profit);
            }
        }

        return maxProfit;
    }
};