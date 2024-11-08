// jai shree ram
// can be solved using Dijoint set also (Krishkals Algo), i dit it with PRIMS ALGO
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() 
{
  int n , m;
  cin >> n >> m;
  vector<vector<vector<int>>> adj(n+1);
  for(int i = 0 ; i < m ; i++) {
    int u , v , w;
    cin >> u >> v >> w;
    adj[u].push_back({v , w});
    adj[v].push_back({u , w});
  }
  priority_queue<pair<ll,ll> , vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
  vector<int> vis(n+1);
  pq.push({0 , 1});
  ll sum = 0;
  int totalNodes = 0;
  while(pq.size()) {
    auto it = pq.top();
    ll node = it.second;
    ll dist = it.first;
    // cout << node << endl;
    pq.pop();
    if(vis[node])
    continue;
    vis[node] = 1;
    sum += dist;
    totalNodes++;
    for(auto i : adj[node]) {
       ll adjNode = i[0];
       ll edgeWt = i[1];
       if(!vis[adjNode]) {
         pq.push({edgeWt , adjNode});
       }
    }
  }
  if(totalNodes != n) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  cout << sum << endl;
}
