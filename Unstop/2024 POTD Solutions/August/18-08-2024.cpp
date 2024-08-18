/*
Asked in Samsung, DE Shaw, Morgan Stanley, and Qualcomm
Problem of the Day: Same Path
Problem Description: https://medium.com/@pradeepsooryavanshee1210/same-path-unstop-solution-a9a35bd05d9d
*/

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int checkIfRoadsCross(int N, int M, vector<int> &A, vector<int> &B)
{
    unordered_set<int> roadSet;

    for (int i = 0; i < N; i++)
    {
        roadSet.insert(A[i]);
    }

    for (int i = 0; i < M; i++)
    {
        if (roadSet.find(B[i]) != roadSet.end())
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < M; i++)
    {
        cin >> B[i];
    }

    cout << checkIfRoadsCross(N, M, A, B) << endl;

    return 0;
}
