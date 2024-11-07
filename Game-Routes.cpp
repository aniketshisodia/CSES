// jai shree ram
 
// GAME ROUTES
#include <bits/stdc++.h>
using namespace std;
 
const int mod = 1e9 + 7;
// topological sort
void dfs(int node , vector<vector<int>> &adj , vector<bool> &vis,  stack<int> &topoSort) {
  vis[node] = true;
  for(auto it : adj[node]) {
      if(!vis[it]) {
          dfs(it , adj , vis , topoSort);
      }
  }
  // stack to store topological sort
  topoSort.push(node);
}
 
int main() 
{
    // Nodes and Edges
    int n , m;
    cin >> n >> m;
    
    // creating adjacency list
    vector<vector<int>> adj(n+1);
    for(int i = 0 ; i < m ; i++) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    // kahn's algorithm
    stack<int> topoSort;
    vector<bool> vis(n+1 , false);
    for(int i = 1; i <=n ; i++) {
        if(!vis[i]) {
            dfs(i , adj , vis , topoSort);
        }
    }
    
    // relaxing Edges
    vector<int> dist(n+1 , 0);
    dist[1] = 1;
    vector<int> parent(n+1 , -1);
    while(topoSort.size()) {
      int node = topoSort.top();
      topoSort.pop();
      int total = 0;
      for(auto it : adj[node]) {
          // cout << node << it << endl;
          dist[it] = ((dist[it]%mod) + (dist[node]%mod))%mod;
      }
    }
    // for(auto i : dist) cout << i << " ";
    // cout << endl;
    cout<<dist[n] % mod;
}
