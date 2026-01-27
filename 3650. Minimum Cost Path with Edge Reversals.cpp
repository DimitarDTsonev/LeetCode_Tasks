// Task : https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/description/?envType=daily-question&envId=2026-01-27

#include <iostream>
#include <vector>
#include <queue>

int minCost(int n, std::vector<std::vector<int>>& edges) {
    std::vector<std::vector<std::pair<int,int>>> adj(n);
    adj.reserve(n);

    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, 2 * w});
    }

    const int INF = 1e9;
    std::vector<int> dist(n, INF);
    dist[0] = 0;

    std::priority_queue<std::pair<int, int>, 
    std::vector<std::pair<int, int>>, 
    std::greater<std::pair<int, int>>> pq;
    pq.push({0, 0});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (u == n - 1)
            return d;
        if (d != dist[u])
            continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return -1;
}

int main() {
    // Example 1:
    int n = 4;
    std::vector<std::vector<int>> edges1 = {
        {0, 1, 3},
        {3, 1, 1},
        {2, 3, 4},
        {0, 2, 2}
    };

    std::cout << "Minimum cost from node 0 to node " 
    << n-1 << " is: " << minCost(n, edges1) << std::endl;

    // Example 2:
    std::vector<std::vector<int>> edges2 = {
        {0, 2, 1},
        {2, 1, 1},
        {2, 1, 1},
        {1, 3, 1}
    };

    std::cout << "Minimum cost from node 0 to node " 
    << n-1 << " is: " << minCost(n, edges2) << std::endl;

    return 0;
}
