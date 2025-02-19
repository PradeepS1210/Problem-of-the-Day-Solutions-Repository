/*
Problem of the Day: Advanced Segregation and Alternating Reversal
Problem Description: https://unstop.com/code/practice/528943
*/

#include <bits/stdc++.h>
using namespace std;

void reverseAlternateGroups(vector<int> &arr, int K) {
    int n = arr.size();
    for (int i = 0; i < n; i += 2 * K) {
        int left = i;
        int right = min(i + K - 1, n - 1);
        while (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

vector<int> mergeAlternately(const vector<int> &list1, const vector<int> &list2) {
    vector<int> merged;
    int i = 0, j = 0, n1 = list1.size(), n2 = list2.size();

    while (i < n1 && j < n2) {
        merged.push_back(list1[i++]);
        merged.push_back(list2[j++]);
    }

    while (i < n1) {
        merged.push_back(list1[i++]);
    }
    while (j < n2) {
        merged.push_back(list2[j++]);
    }

    return merged;
}

int main() {
    int N, x, K;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    cin >> x >> K;

    vector<int> divisible, nonDivisible;
    for (int i = 0; i < N; ++i) {
        if (arr[i] % x == 0) {
            divisible.push_back(arr[i]);
        } else {
            nonDivisible.push_back(arr[i]);
        }
    }

    reverseAlternateGroups(divisible, K);
    reverseAlternateGroups(nonDivisible, K);

    vector<int> result = mergeAlternately(divisible, nonDivisible);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
