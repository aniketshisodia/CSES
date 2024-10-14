// jai shree ram
#include <bits/stdc++.h>
using namespace std;

// int mod = 1e9 + 7;

#define ll long long

int f(int n) {
  int s = 0;
  for(int i = 1 ; i <=  (int) sqrt(n) ;  i++) {
    if(n % i == 0) s+=2;
  }
  int x = sqrt(n);
  if(x * x == n) 
  s -= 1;
  
  return s;
}

int main() 
{
  int n;
  cin>>n;
  vector<int> A(1e6 + 1);
  for(int i = 0 ; i < n; i++) {
    int a;
    cin>>a;
    A[a]++;
  }
  for(int i = 1e6; i >= 1; i--) {
    int f = 0;
    for(int j = i; j <= 1e6; j += i) {
      f += A[j];
    }
    if(f >= 2) {
      cout<<i<<"\n";
      return 0;
    }
  }
  return 0;
}
