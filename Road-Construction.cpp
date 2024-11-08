// jai shree ram
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class DisjointSet {
  public:
    vector<int> parent;
    vector<int> size;
    DisjointSet(int n) {
      parent.resize(n+1 , 0);
      size.resize(n+1 , 1);
      for(int i = 1; i <= n ; i++) {
        parent[i] = i;
      }
    }
    void unionBySize(int u , int v) {
      // if both compo have same size
      int ulp_u = find_ultimate_parent(u);
      int ulp_v = find_ultimate_parent(v);
      if(ulp_v == ulp_u)
      return;
      if(size[ulp_u] >= size[ulp_v]) {
        size[ulp_u] += size[ulp_v];
        parent[ulp_v] = ulp_u;
      }
      else
      if(size[ulp_u] < size[ulp_v]) {
        size[ulp_v] += size[ulp_u];
        parent[ulp_u] = ulp_v;
      }
    }
    int find_ultimate_parent(int node) {
      if(parent[node] == node)
      return node;
      return  parent[node] = find_ultimate_parent(parent[node]);
    }
};

int main() 
{
  int n , m;
  cin >> n >> m;
  DisjointSet ds(n);
  int total_components = n;
  int largest = 0;
  for(int i = 0 ; i <  m ; i++) {
    int u , v;
    cin >> u >> v;
    if(ds.find_ultimate_parent(u) != ds.find_ultimate_parent(v)) {
      ds.unionBySize(u , v);
      int curr = max(ds.size[ds.find_ultimate_parent(u)] , ds.size[ds.find_ultimate_parent(v)]);
      if(curr > largest) {
        largest = curr;
      }
    total_components = total_components - 1;
    }
    cout << total_components << " " << largest << endl;
  }
}
