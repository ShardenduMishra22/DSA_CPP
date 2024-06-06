#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

bool isCyclicDFS(int node, int parent, unordered_map<int,bool>& vis, unordered_map<int,list<int>>& adj) {
    vis[node] = true;
    for (auto neighbour : adj[node]) {
        if (!vis[neighbour]) {
            if (isCyclicDFS(neighbour, node, vis, adj))
                return true;
        } else if (neighbour != parent) {
            return true;
        }
    }
    return false;
}

bool cycleDetectionDFS(vector<vector<int>>& edges, int n, int m) {
    unordered_map<int,list<int>> adj;
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool> vis;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (isCyclicDFS(i, -1, vis, adj))
                return true;
        }
    }
    return false;
}