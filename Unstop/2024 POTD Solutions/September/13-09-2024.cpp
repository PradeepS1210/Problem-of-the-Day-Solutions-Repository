/*
Problem of the Day: Push and Pop
Problem Description: https://medium.com/@pradeepsooryavanshee1210/push-and-pop-unstop-solution-20291ba234ec
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> buildTargetArray(vector<int> &target, int N)
{
    vector<string> operations;
    int currentIndex = 0;

    for (int i = 1; i <= N; ++i)
    {
        if (currentIndex < target.size() && target[currentIndex] == i)
        {
            operations.push_back("Push");
            currentIndex++;
        }
        else if (currentIndex < target.size())
        {
            operations.push_back("Push");
            operations.push_back("Pop");
        }

        if (currentIndex == target.size())
        {
            break;
        }
    }

    return operations;
}

int main()
{
    int M, N;
    cin >> M;
    vector<int> target(M);

    for (int i = 0; i < M; ++i)
    {
        cin >> target[i];
    }

    cin >> N;

    vector<string> result = buildTargetArray(target, N);

    for (const string &op : result)
    {
        cout << op << " ";
    }

    cout << endl;
    return 0;
}