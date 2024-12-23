/*
Problem of the Day: Mutated Virus Mayhem: Maximizing Optimus Destructive Potential
Problem Description: https://unstop.com/code/practice/484668
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int maxMutatedViruses(int V, vector<int>& contaminationLevels) {
    sort(contaminationLevels.begin(), contaminationLevels.end());

    unordered_map<int, int> freq;
    for (int level : contaminationLevels) {
        freq[level]++;
    }

    int mutatedViruses = 0;

    for (int i = 0; i < V; i++) {
        int level = contaminationLevels[i];
        while (freq[level] >= 3) {
            freq[level] -= 3;
            mutatedViruses++;
        }
        while (freq[level] > 0 && freq[level + 1] > 0 && freq[level + 2] > 0) {
            freq[level]--;
            freq[level + 1]--;
            freq[level + 2]--;
            mutatedViruses++;
        }
    }

    return mutatedViruses;
}

int main() {
    int V;
    cin >> V;
    vector<int> contaminationLevels(V);
    for (int i = 0; i < V; i++) {
        cin >> contaminationLevels[i];
    }

    int result = maxMutatedViruses(V, contaminationLevels);
    cout << result << endl;

    return 0;
}
