/*
Problem of the Day: Hypermart
Problem Description: https://medium.com/@pradeepsooryavanshee1210/hypermart-unstop-solution-4dc60a784d75
*/

#include <bits/stdc++.h>
using namespace std;

class HyperMart {
private:
    priority_queue<tuple<int, int, string>, vector<tuple<int, int, string>>, greater<>> inventory;
    int timestamp;

public:
    HyperMart() : timestamp(0) {}

    void addProduct(const string &productName, int quantity) {
        inventory.push({quantity, timestamp++, productName});
    }

    void sellProduct() {
    auto top = inventory.top();
    inventory.pop();
    int quantity = get<0>(top);
    int time = get<1>(top);
    string productName = get<2>(top);
    cout << productName << endl;
}

};

int main() {
    int Q;
    cin >> Q;

    HyperMart mart;
    while (Q--) {
        int actionType;
        cin >> actionType;
        if (actionType == 1) {
            string productName;
            int quantity;
            cin >> productName >> quantity;
            mart.addProduct(productName, quantity);
        } else if (actionType == 2) {
            mart.sellProduct();
        }
    }

    return 0;
}