/*
Problem of the Day: Maximum Price Ticketing
Problem Description: https://unstop.com/code/practice/304758
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> assignTickets(vector<int>& ticketPrices, vector<int>& customerBudgets) {
    multiset<int> tickets(ticketPrices.begin(), ticketPrices.end());
    vector<int> results;

    for (int budget : customerBudgets) {
        auto it = tickets.upper_bound(budget);
        if (it == tickets.begin()) {
            results.push_back(-1);
        } else {
            --it;
            results.push_back(*it);
            tickets.erase(it);
        }
    }

    return results;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> ticketPrices(N);
    vector<int> customerBudgets(M);

    for (int i = 0; i < N; ++i) {
        cin >> ticketPrices[i];
    }

    for (int i = 0; i < M; ++i) {
        cin >> customerBudgets[i];
    }

    vector<int> results = assignTickets(ticketPrices, customerBudgets);

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
