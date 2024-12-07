// Jai Shree Ram
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> dp;

int maxi = 0;

void dfs(int v, int parent) {
    dp[v] = 0; // Initialize dp[v]

    // Process child nodes
    for (auto u : adj[v]) {
        if (u != parent) {
            dfs(u, v);
            dp[v] = max(dp[v], 1 + dp[u]); // Update longest path via child
        }
    }

    // Find the two largest child path lengths
    priority_queue<int> pq;
    for (auto u : adj[v]) {
        if (u != parent) {
            pq.push(dp[u]);
        }
    }

    // Calculate the diameter passing through this node
    if (pq.size() >= 2) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        maxi = max(maxi, first + second + 2); // +2 for edges connecting the paths
    }

    // Update the global diameter with dp[v]
    maxi = max(maxi, dp[v]);
}

void solve() {
    int n;
    cin >> n;

    adj.resize(n);
    dp.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--; // Convert to 0-based index
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    // for (auto i : dp) cout << i << " ";
    // cout << endl;

    cout << maxi; // Diameter of the tree
}

int main() {
    solve();
    return 0;
}
