// jai shree ram
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, m;
    cin >> n >> m;                             // Read the number of nodes and edges
    vector<vector<pair<int, int>>> adj(n + 1); // Adjacency list for the graph

    // Read the edges and their weights
    for (int i = 0; i < m; ++i)
    {
        int u, v, wt;
        cin >> u >> v >> wt;        // Input: edge from u to v with weight wt
        adj[u].emplace_back(v, wt); // Add to adjacency list
    }

    // Distance array initialized with a large value (1e18) to represent infinity
    vector<vector<ll>> dist(2, vector<ll>(n + 1, 1e18));
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;

    // Initialize distances for starting node (node 1)
    dist[0][1] = 0;       // Distance to node 1 without using the coupon
    dist[1][1] = 0;       // Distance to node 1 after using the coupon (same as above)
    pq.push({0, {1, 1}}); // Push starting node into priority queue: {distance, {node, coupon usage flag}}

    // Dijkstra-like logic to calculate minimum distances
    while (!pq.empty())
    {
        auto pr = pq.top(); // Get the node with the smallest distance
        pq.pop();
        ll currDis = pr.first;         // Current distance from source
        int node = pr.second.first;    // Current node
        int coupon = pr.second.second; // Coupon usage flag (0 or 1)

        // If we pop a node that has a distance greater than the known distance, we skip it
        if (currDis > dist[!coupon][node])
            continue;

        // Explore neighbors of the current node
        for (auto it : adj[node])
        {
            ll wt = it.second;      // Weight of the edge
            int adjNode = it.first; // Adjacent node

            // If coupon can still be used (coupon == 1)
            if (coupon == 1)
            {
                // 1. Using the coupon: reduce the weight by half
                if (currDis + wt / 2 < dist[1][adjNode])
                {
                    dist[1][adjNode] = currDis + wt / 2;       // Update distance to adjacent node using coupon
                    pq.push({dist[1][adjNode], {adjNode, 0}}); // Push with coupon used (still can use coupon)
                }
                // 2. If not using the coupon for this edge
                if (currDis + wt < dist[0][adjNode])
                {
                    dist[0][adjNode] = currDis + wt;           // Update distance without using coupon
                    pq.push({dist[0][adjNode], {adjNode, 1}}); // Push with coupon not used
                }
            }
            // If coupon has been used (coupon == 0)
            else
            {
                // 3. Only allow moving to the adjacent node with the original weight
                if (currDis + wt < dist[1][adjNode])
                {
                    dist[1][adjNode] = currDis + wt;           // Update distance without using coupon
                    pq.push({dist[1][adjNode], {adjNode, 0}}); // Push with coupon not used
                }
            }
        }
    }

    // Output the minimum distance to node n
    cout << dist[1][n];
}
