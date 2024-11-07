// jai shree ram
#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); // Unsync iostream for faster I/O
    cin.tie(NULL);                    // Tie cin with NULL for faster input
 
    int n, q;
    cin >> n >> q;
 
    vector<vector<int>> parent(30, vector<int>(n + 1, -1));
 
    // Read input for immediate parent (2^0 parent)
    for (int i = 1; i <= n; i++) {
        cin >> parent[0][i];
    }
 
    // Precompute ancestors for each 2^d distance
    for (int d = 1; d < 30; d++) {
        for (int i = 1; i <= n; i++) {
            if (parent[d - 1][i] != -1) {
                parent[d][i] = parent[d - 1][parent[d - 1][i]];
            }
        }
    }
 
    // Process each query
    while (q--) {
        int node, k;
        cin >> node >> k;
        
        // Calculate log2(k) to limit the bits we need to check
        int maxBit = log2(k) + 1; // log2 is faster than repeatedly going to 30
 
        for (int i = 0; i < maxBit && node != -1; i++) {
            if (k & (1 << i)) {
                node = parent[i][node];
            }
        }
        
        cout << node << '\n';
    }
}
