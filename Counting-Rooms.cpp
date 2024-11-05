// jai shree ram
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m)), vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    // Input grid and mark cells as blocked (0) or open (1)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            if (ch == '#')
                A[i][j] = 0;
            else
                A[i][j] = 1;
        }
    }

    // Direction vectors for moving up, left, down, and right
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, -1, 0, 1};

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {  // This should be m instead of n
            if (A[i][j] && !vis[i][j]) {
                q.push({i, j});
                vis[i][j] = 1;
                ans++;

                // Breadth-First Search (BFS) to mark all connected cells
                while (!q.empty()) {
                    auto it = q.front();
                    int r = it.first;
                    int c = it.second;
                    q.pop();

                    // Explore neighbors
                    for (int s = 0; s < 4; s++) {
                        int nrow = drow[s] + r;
                        int ncol = dcol[s] + c;

                        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && A[nrow][ncol]) {
                            q.push({nrow, ncol});
                            vis[nrow][ncol] = 1; // Corrected: mark (nrow, ncol) as visited
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
