// jai shree ram

// LONGEST FLIGHT ROUTE
#include <bits/stdc++.h>
using namespace std;

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
    vector<int> dist(n+1 , INT_MIN);
    dist[1] = 0;
    vector<int> parent(n+1 , -1);
    while(topoSort.size()) {
      int node = topoSort.top();
      // cout<<node<<endl;
      topoSort.pop();
      for(auto it : adj[node]) {
          if(dist[node] + 1 > dist[it]) {
            dist[it] = dist[node] + 1;
            parent[it] = node;
          }
      }
    }
    if(dist[n] == INT_MIN) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        //  retracing the path
        vector<int> cycle;
        cycle.push_back(n);
        while(parent[cycle.back()] != -1) {
          cycle.push_back(parent[cycle.back()]);
        }
        reverse(cycle.begin() , cycle.end());
        if(cycle[0] != 1) {
          cout << "IMPOSSIBLE\n";
          return 0;
        }
        cout << cycle.size() << endl;
        for(auto it : cycle) cout << it << " ";
    }
}
