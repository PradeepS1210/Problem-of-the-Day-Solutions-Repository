/*
Problem of the Day: Count the number of elements divisible by integer K
Problem Description: https://medium.com/@pradeepsooryavanshee1210/count-the-number-of-elements-divisible-by-integer-k-unstop-solution-f6de5969eba2
*/

#include <bits/stdc++.h>

using namespace std;

int countDivisibleNumbers(const vector<int>& arr, int K) {
    set<int> uniqueNumbers;
    int N = arr.size();

    vector<string> strArr;
    for (int num : arr) {
        strArr.push_back(to_string(num));
    }

    for (int length = 1; length <= N; ++length) {
        vector<bool> select(N, false);
        fill(select.begin(), select.begin() + length, true);

        do {
            string currentNum = "";
            for (int i = 0; i < N; ++i) {
                if (select[i]) {
                    currentNum += strArr[i];
                }
            }

            sort(currentNum.begin(), currentNum.end());
            do {
                int num = stoi(currentNum);
                if (num % K == 0) {
                    uniqueNumbers.insert(num);
                }
            } while (next_permutation(currentNum.begin(), currentNum.end()));

        } while (prev_permutation(select.begin(), select.end()));
    }

    return uniqueNumbers.size();
}

int main() {
    int K, N;
    cin >> K >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int result = countDivisibleNumbers(arr, K);
    cout << result << endl;

    return 0;
}