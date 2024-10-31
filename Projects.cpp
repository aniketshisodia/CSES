// jai shree ram
#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
ll f(int i, vector<vector<int>> &A, vector<ll> &dp) {
  if (i == A.size()) return 0;
  if (dp[i] != -1) return dp[i];
  
  ll inc = 0, exc = 0;
  exc = f(i + 1, A, dp);
  
  // Find the next index where the interval starts after A[i]'s end time
  auto it = upper_bound(A.begin(), A.end(), vector<int>{A[i][1], INT_MAX, INT_MAX}, 
                        [](const vector<int> &a, const vector<int> &b) {
                          return a[0] < b[0];
                        }) - A.begin();
  
  inc = A[i][2] + f(it, A, dp);
  
  return dp[i] = max(inc, exc);
}
 
int main() {
  int n;
  cin >> n;
  vector<vector<int>> A;
  for (int i = 0; i < n; i++) {
    int l, r, c;
    cin >> l >> r >> c;
    A.push_back({l, r, c});
  }
  sort(A.begin(), A.end());
  
  vector<ll> dp(n, -1);
  cout << f(0, A, dp) << endl;
}
