// jai shree ram
#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> A(n+1) , pos(n+1);
    for(int i = 1; i <= n; i++) {
      cin>>A[i];
      pos[A[i]] = i;
    }
    int ans = 1;
    for(int i = 1; i < n; i++) {
      if(pos[i] > pos[i+1]) {
        ans++;
      }
    }
    while(m--) {
      int l , r;
      cin>>l>>r;
      set<pair<int,int>> st;
      if(A[l] + 1 <= n) {
        st.insert({A[l] , A[l] + 1});
      }
      if(A[r] + 1 <= n) {
        st.insert({A[r] , A[r] + 1});
      }
      if(A[l] > 1) {
        st.insert({A[l] - 1 , A[l]});
      }
      if(A[r] > 1) {
        st.insert({A[r] - 1 , A[r]});
      }
      for(auto it : st) {
        int f = it.first , s = it.second;
        ans -= (pos[f] > pos[s]);
      }
      int t = A[l];
      A[l] = A[r];
      A[r] = t;
      pos[A[l]] = l;
      pos[A[r]] = r;
      for(auto it : st) {
        int f = it.first , s = it.second;
        ans += (pos[f] > pos[s]);
      }
      cout<<ans<<"\n";  
    }
    return 0;
}
