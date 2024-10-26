// jai shree ram
#include <bits/stdc++.h>
using namespace std;
int main() 
{
  int n;
  cin>>n;
  queue<int> q;
  for(int i = 1 ; i <= n ; i++) {
    q.push(i);
  }
  bool flag = false;
  while(q.size()) {
    auto it = q.front();
    q.pop();
    if(flag) {
      cout<<it<<" ";
    }
    else q.push(it);
    flag = !flag;
  }
  
  return 0;
}
