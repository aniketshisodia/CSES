#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll f(const vector<int>& A, ll time) {
  ll canMake = 0;
  for (int i = 0; i < A.size(); i++) {
    canMake += time / A[i];
  }
  return canMake;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  ll ans = 1e18; // Use a larger value for initial ans to avoid overflow issues
  ll low = 1, high = 1e18; // Higher initial value for `high`
  
  while (low <= high) {
    ll mid = low + (high - low) / 2; // Binary search
    ll canMake = f(A, mid);
    
    if (canMake >= k) {
      ans = min(ans, mid);
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  
  cout << ans << endl;
}
