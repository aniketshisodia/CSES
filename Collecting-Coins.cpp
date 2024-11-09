// jai shree ram
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

// Finding insertion time of nodes
void dfs1(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& s) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs1(it, adj, vis, s);
        }
    }
    s.push(node); // store nodes in the order of completion time
}

// Traversing in reverse graph to find SCCs
void dfs2(int node, vector<vector<int>>& adjT, vector<int>& vis, vector<int>& group, int k) {
    vis[node] = 1;
    group[node] = k; // assign component id `k`
    for(auto it : adjT[node]) {
        if(!vis[it]) {
            dfs2(it, adjT, vis, group, k);
        }
    }
}

// DP function to find max coins starting from a given SCC node
ll f(int node, vector<vector<int>>& adjSCC, vector<ll>& dp, vector<ll>& sum_of_coins) {
    if(dp[node] != -1) return dp[node]; // return precomputed value
    dp[node] = sum_of_coins[node]; // initialize with sum of coins in this SCC
    for(auto it : adjSCC[node]) {
        dp[node] = max(dp[node], f(it, adjSCC, dp, sum_of_coins) + sum_of_coins[node]);
    }
    return dp[node];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> coins(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> coins[i];
    }

    // Graphs and their transpose for SCC finding
    vector<vector<int>> adj(n + 1), adjT(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);  // original graph
        adjT[v].push_back(u); // transpose graph
    }

    // Step 1: Fill stack based on finish time of DFS
    stack<int> s;
    vector<int> vis(n + 1);
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs1(i, adj, vis, s);
        }
    }

    // Step 2: Find SCCs using transpose graph in stack order
    vector<int> group(n + 1); // group[i] will store SCC id for node `i`
    int k = 0; // SCC counter
    vis.assign(n + 1, 0); // reset visitation for SCC finding
    while(!s.empty()) {
        int node = s.top(); s.pop();
        if(!vis[node]) {
            k++; // new SCC id
            dfs2(node, adjT, vis, group, k);
        }
    }

    // Step 3: Sum coins in each SCC
    vector<ll> sum_of_coins(k + 1, 0); // sum of coins for each SCC
    for(int i = 1; i <= n; i++) {
        sum_of_coins[group[i]] += coins[i];
    }

    // Step 4: Build SCC graph
    vector<vector<int>> adjSCC(k + 1); // SCC adjacency list
    for(int i = 1; i <= n; i++) {
        for(int v : adj[i]) {
            if(group[i] != group[v]) {
                adjSCC[group[i]].push_back(group[v]); // edge between different SCCs
            }
        }
    }

    // Step 5: DP to find max coins
    vector<ll> dp(k + 1, -1); // dp[i] stores max coins collectible starting from SCC `i`
    ll ans = 0;
    for(int i = 1; i <= k; i++) {
        if(dp[i] == -1) { // only calculate if not already computed
            ans = max(ans, f(i, adjSCC, dp, sum_of_coins));
        }
    }

    cout << ans << endl; // final answer
    return 0;
}
