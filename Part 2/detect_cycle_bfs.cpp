#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

bool isCyclicBFS(unordered_map<int,list<int>>& adj, unordered_map<int,bool>& vis,int src) {
    unordered_map<int,int> parent;
    parent[src] = -1;
    vis[src] = true;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (auto neighbour : adj[front]) {
            if (!vis[neighbour]) {
                vis[neighbour] = true;
                parent[neighbour] = front;
                q.push(neighbour);
            } else if (neighbour != parent[front]) {
                return true;
            }
        }
    }
    return false;
}

string cycleDetectionBFS(vector<vector<int>>& edges, int n, int m) {
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
            if (isCyclicBFS(adj, vis, i))
                return "Yes";
        }
    }
    return "No";
}

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    cout << "Enter the edges (vertex u and v): \n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    cout << "Cycle detection result using BFS: " << cycleDetectionBFS(edges, n, m) << endl;
    return 0;
}
