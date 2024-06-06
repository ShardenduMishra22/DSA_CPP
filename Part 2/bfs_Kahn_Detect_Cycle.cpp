#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool has_cycle(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> indegree(n, 0);
    queue<int> q;
    int visited_nodes = 0;

    for (int i = 0; i < n; ++i) {
        for (int neighbor : adj[i]) {
            indegree[neighbor]++;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        visited_nodes++;

        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return visited_nodes != n;
}

