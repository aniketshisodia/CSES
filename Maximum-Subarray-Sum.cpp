// jai shree ram

// kadane algorithm 
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() 
{
    int n;
    cin >> n;
    vector<ll> A(n);
    for(int i = 0 ; i < n; i++) {
      cin>>A[i];
    }
    ll currentSum , maximumSum = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
      if(i == 0) {
        currentSum = A[i];
        maximumSum = A[i];
        continue;
      }
      if(currentSum < 0) 
      currentSum = A[i];
      else
      currentSum = currentSum + A[i];
      
      maximumSum = max(maximumSum , currentSum);
    }
    cout<<maximumSum;
    return 0;
}

