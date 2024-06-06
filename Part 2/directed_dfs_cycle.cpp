#include <iostream>
#include <vector>

using namespace std;

bool detect_cycle(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& dfs_vis) {
    visited[node] = true;
    dfs_vis[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (detect_cycle(neighbor, adj, visited, dfs_vis)) {
                return true;
            }
        } else if (dfs_vis[neighbor]) {
            return true;
        }
    }

    dfs_vis[node] = false;
    return false;
}

bool has_cycle(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<bool> dfs_vis(n, false);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (detect_cycle(i, adj, visited, dfs_vis)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    vector<vector<int>> adj = {
        {1},
        {2},
        {3},
        {4},
        {1}
    };

    cout << boolalpha << has_cycle(adj) << endl;  // Output: true (graph has a cycle)

    return 0;
}
