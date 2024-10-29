/*
Problem of the Day: Kingdom l problem
problem Description: https://medium.com/@pradeepsooryavanshee1210/kingdom-l-problem-unstop-solution-8f18bfba9890
*/

#include <iostream>
#include <vector>

using namespace std;

class Pair {
public:
    int x, y;
    Pair(int x, int y) : x(x), y(y) {}
};

int ipositionking = -1;
int jpositionking = -1;
int totalnumerofsoilder = 0;
int ikingtreval = -1;
int jkingtreval = -1;
int newk = -1;
int kadd = 0;
vector<Pair> l;

void kingtreval(vector<vector<int>>& vis, int i, int j) {
    ikingtreval = jkingtreval = newk = -1;
    int a = i, b = j;
    
    for (int visi = 0; visi < vis.size(); visi++) {
        if (vis[visi][b] != 0 && kadd > vis[visi][b]) {
            kadd += vis[visi][b];
            ikingtreval = visi;
            jkingtreval = b;
            newk = vis[visi][b];
            l.push_back(Pair(ikingtreval, jkingtreval));
            break;
        }
    }

    for (int visi = 0; visi < vis[0].size(); visi++) {
        if (newk != -1) break;
        if (vis[a][visi] != 0 && kadd > vis[a][visi]) {
            kadd += vis[a][visi];
            ikingtreval = a;
            jkingtreval = visi;
            newk = vis[a][visi];
            l.push_back(Pair(ikingtreval, jkingtreval));
            break;
        }
    }

    a = i;
    b = j;
    while (a >= 0 && b >= 0 && newk == -1) {
        if (vis[a][b] != 0 && kadd > vis[a][b]) {
            ikingtreval = a;
            jkingtreval = b;
            newk = vis[a][b];
            l.push_back(Pair(ikingtreval, jkingtreval));
            break;
        }
        a--;
        b--;
    }

    a = i;
    b = j;
    while (a < vis.size() && b < vis[0].size() && newk == -1) {
        if (vis[a][b] != 0 && kadd > vis[a][b]) {
            kadd += vis[a][b];
            ikingtreval = a;
            jkingtreval = b;
            newk = vis[a][b];
            l.push_back(Pair(ikingtreval, jkingtreval));
            break;
        }
        a++;
        b++;
    }

    a = i;
    b = j;
    while (a < vis.size() && b >= 0 && newk == -1) {
        if (vis[a][b] != 0 && kadd > vis[a][b]) {
            kadd += vis[a][b];
            ikingtreval = a;
            jkingtreval = b;
            newk = vis[a][b];
            l.push_back(Pair(ikingtreval, jkingtreval));
            break;
        }
        a++;
        b--;
    }

    a = i;
    b = j;
    while (a >= 0 && b < vis[0].size() && newk == -1) {
        if (vis[a][b] != 0 && kadd > vis[a][b]) {
            kadd += vis[a][b];
            ikingtreval = a;
            jkingtreval = b;
            newk = vis[a][b];
            l.push_back(Pair(ikingtreval, jkingtreval));
            break;
        }
        a--;
        b++;
    }
}

string isQueensafe(vector<vector<int>>& matrix, int ipositionking, int jpositionking) {
    ikingtreval = ipositionking;
    jkingtreval = jpositionking;

    while (ikingtreval != -1 && jkingtreval != -1) {
        matrix[ikingtreval][jkingtreval] = 0;
        ikingtreval = jkingtreval = -1;
        kingtreval(matrix, ipositionking, jpositionking);
        
        if (newk == -1) break;
        
        if (ikingtreval != -1 && jkingtreval != -1) {
            totalnumerofsoilder--;
            ipositionking = ikingtreval;
            jpositionking = jkingtreval;
        }
        newk = -1;
    }
    
    return totalnumerofsoilder != 0 ? "Lose" : "Save and path as i and j format";
}

string issafe(vector<vector<int>>& matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                ipositionking = i;
                jpositionking = j;
            }
            if (matrix[i][j] != -1 && matrix[i][j] != 0) {
                totalnumerofsoilder++;
            }
        }
    }
    
    return isQueensafe(matrix, ipositionking, jpositionking);
}

int main() {
    int k, n, m;
    cin >> k >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    kadd += k;
    string result = issafe(arr, n, m);
    cout << result << endl;

    if (!l.empty() && totalnumerofsoilder == 0) {
        for (const auto& p : l) {
            cout << p.x << " " << p.y << endl;
        }
    }

    return 0;
}
