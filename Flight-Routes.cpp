// jai shree ram
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
 
int  main()
{
    ll  n, m;
    cin >> n >> m;
    vector<vector<vector<ll >>> adj(n + 1);
    while (m--)
    {
        ll  a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        // adj[b].push_back({a, c});
    }
    set<pair<ll , ll >> s;
    s.insert({0, 1});
    vector<ll > dist(n + 1,LONG_MAX);
    dist[1] = 0;
    while (s.size())
    {
        auto it = *(s.begin());
        ll  node = it.second;
        ll  wt = it.first;
        // cout<<node<<endl;
        s.erase(it);
        for (auto i : adj[node])
        {
            ll  adjNode = i[0];
            ll  adjWt = i[1];
            // cout<<adjNode<<" "<<adjWt<<"\n";
            if (adjWt + wt < dist[adjNode])
            {
              // cout<<adjNode;
              if(dist[adjNode] != LONG_MAX) 
              s.erase({dist[adjNode] , adjNode});
                dist[adjNode] = adjWt + wt;
                s.insert({dist[adjNode] , adjNode});
            }
        }
    }
    for (ll  i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}
