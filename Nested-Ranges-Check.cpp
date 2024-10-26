// jai shree ram
#include <bits/stdc++.h>
using namespace std;

// comparator function
bool cmp(vector<int> a , vector<int> b) {
  if(a[0] != b[0])
  return a[0] < b[0];
  return a[1] > b[1];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> A;
    map<pair<int,int> , int> mp;
    for(int i = 0; i < n; i++) {
        int a , b;
        cin>>a>>b;
        A.push_back({a , b});
        mp[{a,b}] = i;
    }
    sort(A.begin(),A.end(),cmp);
    vector<int> res1(n) , res2(n);
    int maxr = 0;
    int minr = 1e9 + 1;
    for(int i = n - 1; i >= 0; i--) {
      if(A[i][1] >= minr) {
        res1[mp[{A[i][0] , A[i][1]}]] = 1;
      }
      minr = min(minr , A[i][1]);
    }
    for(int i = 0 ; i < A.size(); i++) {
      if(A[i][1] <= maxr) {
        res2[mp[{A[i][0] , A[i][1]}]] = 1;
      }
        maxr = max(A[i][1] , maxr);
    }
    for(auto i : res1) cout<<i<<" ";
    cout<<endl;
    for(auto i : res2) cout<<i<<" ";
}
