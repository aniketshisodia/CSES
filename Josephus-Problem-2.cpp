// jai shree ram
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Define the ordered_set type
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    int n, k;
    cin >> n >> k;
    ordered_set s;
    for(int i = 1; i <= n; i++) {
        s.insert(i);
    }

    int startPos = 0;
    while(s.size()) {
      startPos = startPos % s.size();
      int posToRemove = (startPos + k) % s.size();
      startPos = posToRemove;
      auto t =  s.find_by_order(posToRemove);
      cout<<*t<<" ";
      s.erase(t);
    }
    return 0;
}
