/*
Problem of the Day: Maximum GCD Score
Problem Description: https://unstop.com/code/practice/535226
*/

#include <bits/stdc++.h>
using namespace std;

int computeGCD(int a, int b) {
    return b == 0 ? a : computeGCD(b, a % b);
}

int getMaxScore(vector<int> &A) {
    int n = A.size();
    multiset<int> B;
    int maxScore = 0;
   
    sort(A.rbegin(), A.rend());

    B.insert(A[0]);
    A.erase(A.begin());

    for (int i = 0; i < n - 1; i++) {
        int currentMaxGCD = 0;
        int bestElement = -1;

        for (auto elem : A) {
            for (auto bElem : B) {
                int gcd = computeGCD(elem, bElem);
                if (gcd > currentMaxGCD) {
                    currentMaxGCD = gcd;
                    bestElement = elem;
                }
            }
        }

        maxScore += currentMaxGCD;
        A.erase(find(A.begin(), A.end(), bestElement));
        B.insert(bestElement);
    }

    return maxScore;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cout << getMaxScore(A) << endl;
    return 0;
}
