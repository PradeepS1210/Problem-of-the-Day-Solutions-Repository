/*
Asked in Uber, FedEx, Xome, mathworks, Zomato
Problem of the Day: Projection Area of 3D Shapes
Problem Description: https://medium.com/@pradeepsooryavanshee1210/projection-area-of-3d-shapes-unstop-solution-2fd59e3d1e3b
*/

#include <bits/stdc++.h>
using namespace std;

int projectionArea(vector<vector<int>> &grid)
{
    int N = grid.size();
    int xyProjection = 0, yzProjection = 0, zxProjection = 0;

    for (int i = 0; i < N; ++i)
    {
        int maxRow = 0;
        int maxCol = 0;
        for (int j = 0; j < N; ++j)
        {
            if (grid[i][j] > 0)
            {
                xyProjection++;
            }
            maxRow = max(maxRow, grid[i][j]);
            maxCol = max(maxCol, grid[j][i]);
        }
        zxProjection += maxRow;
        yzProjection += maxCol;
    }

    return xyProjection + yzProjection + zxProjection;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> grid(N, vector<int>(N));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> grid[i][j];
        }
    }

    cout << projectionArea(grid) << endl;

    return 0;
}