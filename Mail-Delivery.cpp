// jai shree ram
// Euler Path 
// Euler Cycle

#include <bits/stdc++.h>
using namespace std;

vector<int> EulerPath;

// i can visit the same node 
// but not the same edge
void dfs(int node , vector<vector<pair<int,int>>> &adj , vector<int> &visitedEdges) {
    while(adj[node].size()) {
        auto [adjNode , edge_idx] = adj[node].back();
        adj[node].pop_back();
        if(visitedEdges[edge_idx]) 
        continue;
        visitedEdges[edge_idx] = 1;
        dfs(adjNode , adj , visitedEdges);
    }
    EulerPath.push_back(node);
}

int main() 
{
    int n , m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<int> degree(n+1);
    vector<int> visitedEdges(m+1);
    for(int i = 1 ; i <= m ; i++) {
      int u , v ;
      cin >> u >> v;
      adj[u].push_back({v , i});
      adj[v].push_back({u , i});
      degree[u]++ , degree[v]++;
    }
    for(int i = 1 ; i <= n ; i++) {
      if(degree[i] % 2) {
        cout << "IMPOSSIBLE\n";
        return 0;
      }
    }
    dfs(1 , adj , visitedEdges);
    if(EulerPath.size() != m + 1) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
    for(auto i : EulerPath) cout << i << " ";
}
