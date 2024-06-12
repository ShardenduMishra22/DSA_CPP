#include <bits/stdc++.h>
using namespace std;

#define fr(i, len) for(int i = 0; i < len; i++)
#define YES cout<<"Yes \n";
#define NO cout<<"No \n";
#define nl cout<<"\n";

typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<bool> vbool;

void dfs(int u, int &timer, vint &disc, vint &low, vbool &vis, vint &prnt, vbool &articulation, unordered_map<int, list<int>> &adj) {
    vis[u] = true;
    disc[u] = low[u] = ++timer;
    int children = 0;

    for (int v : adj[u]){
        if (!vis[v]) {
            children++;
            prnt[v] = u;
            dfs(v, timer, disc, low, vis, prnt, articulation, adj);

            low[u] = min(low[u], low[v]);

            if (prnt[u] == -1 && children > 1) {
                articulation[u] = true;
            }
            if (prnt[u] != -1 && low[v] >= disc[u]) {
                articulation[u] = true;
            }
        } else if (v != prnt[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

vint findArticulationPoints(vvint &edges, int V) {
    unordered_map<int, list<int>> adj;
    for (auto &edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vint disc(V, -1), low(V, -1), prnt(V, -1);
    vbool vis(V, false), articulation(V, false);
    int timer = 0;

    fr(i, V) {
        if (!vis[i]) {
            dfs(i, timer, disc, low, vis, prnt, articulation, adj);
        }
    }

    vint result;
    fr(i, V) {
        if (articulation[i]) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int V = 5; // Number of vertices
    vvint edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {3, 4}}; // Edges

    vint articulationPoints = findArticulationPoints(edges, V);

    for (int point : articulationPoints) {
        cout << "Articulation Point: " << point << "\n";
    }

    return 0;
}
