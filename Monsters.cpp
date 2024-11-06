#include <bits/stdc++.h>
using namespace std;

int x, y;
//            U   L   D   R
int drow[] = {-1, 0, 1, 0};
int dcol[] = {0, -1, 0, 1};

// Function to retrace the path
void retrace(vector<vector<int>> &dist, int row, int col, string &ans) {
    while (dist[row][col] != 0) {
        for (int s = 0; s < 4; s++) {
            int nrow = row + drow[s];
            int ncol = col + dcol[s];
            if (nrow >= 0 && ncol >= 0 && nrow < dist.size() && ncol < dist[0].size()) {
                if (dist[nrow][ncol] + 1 == dist[row][col]) {
                    if (s == 0) ans.push_back('D');
                    if (s == 1) ans.push_back('R');
                    if (s == 2) ans.push_back('U');
                    if (s == 3) ans.push_back('L');
                    row = nrow;
                    col = ncol;
                    break;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<vector<int>> A(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            if (ch == '#') {
                A[i][j] = 0;
            } else if (ch == 'M') {
                q.push({i, j});
                A[i][j] = 1;
                dist[i][j] = 0;
            } else if (ch == '.') {
                A[i][j] = 1;
            } else {
                A[i][j] = 1;  // A (start position)
                x = i;
                y = j;
            }
        }
    }

    // BFS for minimum distance from monsters
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for (int s = 0; s < 4; s++) {
            int nrow = i + drow[s];
            int ncol = j + dcol[s];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && A[nrow][ncol]) {
                if (dist[nrow][ncol] > dist[i][j] + 1) {
                    dist[nrow][ncol] = dist[i][j] + 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    // BFS to find shortest escape path from start (x, y)
    q.push({x, y});
    dist[x][y] = 0;
    int X = -1, Y = -1, f = 0;
    while (!q.empty() && !f) {
        auto [i, j] = q.front();
        q.pop();
        if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
            X = i;
            Y = j;
            f = 1;
            break;
        }
        for (int s = 0; s < 4; s++) {
            int nrow = i + drow[s];
            int ncol = j + dcol[s];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && A[nrow][ncol]) {
                if (dist[nrow][ncol] > dist[i][j] + 1) {
                    dist[nrow][ncol] = dist[i][j] + 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    if (!f) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        string ans;
        retrace(dist, X, Y, ans);
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
}
