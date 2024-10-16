// jai shree ram
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    
    int k;
    cin>>k;
    
    vector<int> A(n);
    
    map<int , int> mp;
    
    for(int i = 0 ; i < n; i++) {
      cin>>A[i];
      mp[A[i]] = i;
    }
    
    for(int i = 0 ; i < n; i++) {
      if(mp.find(k - A[i]) != mp.end() && mp[k - A[i]] != i) {
        cout<<i + 1<<" "<<mp[k - A[i]] + 1;
        return 0;
      }
    }
    
    cout<<"IMPOSSIBLE\n";
     
    return 0;
}

