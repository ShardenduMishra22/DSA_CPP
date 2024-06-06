#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adj;
    stack<int> s; 

    void addEdge(int u, int v, int weight) {
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }


    // stack is only for topological sort
    void dfs(int i, unordered_map<int, bool>& vis) {
        vis[i] = true;
        for (auto& j : adj[i]) {
            if (!vis[j.first]) {
                dfs(j.first, vis);
            }
        }
        s.push(i);
    }

    void DFS(int n) {
        unordered_map<int, bool> vis;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis);
            }
        }
    }

    vector<int> shortestPath(int src, int n) {
        DFS(n);

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while (!s.empty()) {
            int top = s.top();
            s.pop();

            for (auto& neighbor : adj[top]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (dist[top] != INT_MAX && dist[top] + weight < dist[v]) {
                    dist[v] = dist[top] + weight;
                }
            }
        }

        return dist;
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 5);
    g.addEdge(1, 3, 10);
    g.addEdge(2, 3, 3);

    int src = 0;
    int n = 4; 

    vector<int> shortest = g.shortestPath(src, n);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": ";
        if (shortest[i] == INT_MAX) {
            cout << "INF\n";
        } else {
            cout << shortest[i] << "\n";
        }
    }

    return 0;
}
