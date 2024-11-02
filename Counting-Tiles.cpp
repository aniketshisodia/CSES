// jai shree ram
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int mod = 1e9 + 7;
int dp[1000][10];
void g(int i , int curr_mask , int new_mask , int n , vector<int> &A) {
  if(i == n) {
    // cout<<new_mask<<endl;
    A.push_back(new_mask);
    return;
  }
  if((curr_mask & (1 << i)) == 0) {
    // then i can definately put a horizontal tile
    new_mask = new_mask | (1 << i);
    g(i + 1 , curr_mask , new_mask , n , A);
    new_mask = new_mask ^ (1 << i);
    //  either i can put a vertical tile 
    // but i can put it only when we are not at the last row
    // And new bit is also '0'
    if(i < n - 1 && (curr_mask & (1 << (i + 1))) == 0) {
      g(i + 2 , curr_mask , new_mask , n , A);
    }
  }
  else {
    g(i + 1 , curr_mask , new_mask , n , A);
  }
}

ll f(int col , int mask , int n , int m) {
  if(col == m) {
    if(mask == 0) {
      return 1;
    }
    return 0;
  }
  if(dp[col][mask] != -1) 
    return dp[col][mask] % mod;
  // generate all the poossible mask
  vector<int> next_masks;
  g(0 , mask , 0 , n , next_masks);
  ll ans = 0;
  for(int next_mask : next_masks) {
    ans = (ans + f(col + 1 , next_mask , n , m) % mod ) % mod;
  }
  return dp[col][mask] = ans % mod;
}

int main() 
{
  int n , m;
  cin >> n >> m;
  memset(dp , -1 , sizeof(dp));
  cout<<f(0 , 0 , n , m) % mod;
  return 0;
}
