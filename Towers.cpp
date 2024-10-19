// Jai Shree Ram
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) 
        cin >> A[i];

    multiset<int> ms;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        auto it = ms.upper_bound(A[i]);

        if (it == ms.end()) {
            ans++;  // New increasing subsequence required
        } else {
            ms.erase(it);  // Replace with a smaller value
        }
        ms.insert(A[i]);
    }

    cout << ans << "\n";
    return 0; 
}
