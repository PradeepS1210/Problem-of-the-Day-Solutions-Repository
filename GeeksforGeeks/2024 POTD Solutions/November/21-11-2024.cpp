/*
Asked in Paytm, Flipkart +21 more
Problem of the Day: Stock Buy and Sell — Multiple Transaction Allowed
Problem Description: https://medium.com/@pradeepsooryavanshee1210/stock-buy-and-sell-multiple-transaction-allowed-geeksforgeeks-solution-ea2dc6e9b2e1
*/

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }

        return maxProfit;
    }
};