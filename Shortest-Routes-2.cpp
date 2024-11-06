#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define INF LONG_LONG_MAX
 
int main() {
    ll n, m, q;
    cin >> n >> m >> q;
 
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, INF));
 
    // Distance to itself is 0
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }
 
    // Reading the graph edges
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        dp[a][b] = min(c, dp[a][b]);
        dp[b][a] = min(c, dp[b][a]);  // Since the graph is undirected
    }
 
    // Applying Floyd-Warshall Algorithm
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][k] != INF && dp[k][j] != INF) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }
 
    // Processing queries
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (dp[a][b] != INF) {
            cout << dp[a][b] << endl;
        } else {
            cout << -1 << endl;
        }
    }
 
    return 0;
}
