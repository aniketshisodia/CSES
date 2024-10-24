// jai shree ram
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int main() 
{
    int n , m;
    cin>>n>>m;
    vector<int> A(n);
    for(int i = 0 ; i < n ; i++) {
      cin>>A[i];
    }
    vector<vector<int>> dp(n+1 , vector<int> (m + 2));
    // base condtion
    for(int k = 1; k <= m ; k++) {
      if(A[0] == 0) {
        dp[1][k] = 1;
      }
      else {
        dp[1][A[0]] = 1;
        break;
      }
    }
    for(int i = 2 ; i <= n ; i++) {
      if(A[i - 1] == 0) {
        for(int k = 1 ;  k <= m ; k++) {
          dp[i][k] = (((dp[i - 1][k] + dp[i - 1][k - 1]) % mod) + dp[i - 1][k + 1])%mod;
        }
      }
      else {
        int x = A[i-1];
        dp[i][x] = (((dp[i - 1][x] + dp[i - 1][x - 1]) % mod) + dp[i - 1][x + 1]) % mod;
      }
    }
    int result = 0;
    for(int k = 1; k <= m ; k++) {
      result = (result + dp[n][k])%mod;
    }
    cout<<result<<"\n";
}
