/*
Problem of the Day: Rotate by 90 degree
Problem Description: https://medium.com/@pradeepsooryavanshee1210/rotate-by-90-degree-geeksforgeeks-solution-a30425fc69af
*/

void rotate(vector<vector<int>>& mat) {
    int n = mat.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        reverse(mat[i].begin(), mat[i].end());
    }
}