// jai shree ram

// sum of divisors
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9 + 7;

ll BinaryExp(ll base , ll exponent) {
  if(exponent == 0) {
    return 1;
  }
  ll result = BinaryExp(base , exponent/2);
  if(exponent % 2 == 1) {
    return (((result*result) % mod) * base) % mod;
  }
  else 
    return (result * result) % mod;
}

int main() 
{
  ll n;
  cin>>n;
  ll answer = 0;
  for(ll i = 1 , j ;  i <= n; i = j) {
    ll q = n / i;
    j = n / q + 1;
    ll rangeSumUptoJMinus1    = ((((j%mod)*((j-1)%mod))%mod)*BinaryExp(2,mod-2))%mod;
    ll rangeSumUptoIMinus1    = ((((i%mod)*((i-1)%mod))%mod)*BinaryExp(2,mod-2))%mod;
    ll rangeSumWithQuotientQ  = (rangeSumUptoJMinus1 - rangeSumUptoIMinus1 + mod)%mod;
    answer = (answer + (q%mod) * (rangeSumWithQuotientQ) ) % mod;
  }
  cout<<answer<<"\n";
  return 0;
}
