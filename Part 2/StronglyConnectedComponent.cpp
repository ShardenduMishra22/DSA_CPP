#include <bits/stdc++.h>
using namespace std;

#define fr(i, len) for(int i = 0; i < len; i++)

typedef vector<int> vint;
typedef vector<vector<int>> vvint;

void dfs(int node, vector<bool> &vis, stack<int> &st, vector<vector<int>> &adj) {
    vis[node] = true;
    for (int neighbour : adj[node]) {
        if (!vis[neighbour]) {
            dfs(neighbour, vis, st, adj);
        }
    }
    st.push(node);
}

void reverseDfs(int node, vector<bool> &vis, vector<vector<int>> &transpose, vint &cmp) {
    vis[node] = true;
    cmp.push_back(node);
    for (int neighbour : transpose[node]) {
        if (!vis[neighbour]) {
            reverseDfs(neighbour, vis, transpose, cmp);
        }
    }
}

vector<vector<int>> findSCCs(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    vector<vector<int>> transpose(V);
    fr(i, edges.size()) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    
    stack<int> st;
    vector<bool> vis(V, false);
    
    fr(i, V) {
        if (!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }
    
    fr(i, V) {
        for (int neighbour : adj[i]) {
            transpose[neighbour].push_back(i);
        }
    }
    
    fill(vis.begin(), vis.end(), false);
    vector<vector<int>> sccs;
    
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        
        if (!vis[node]) {
            vint cmp;
            reverseDfs(node, vis, transpose, cmp);
            sccs.push_back(cmp);
        }
    }
    
    return sccs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int V = 5; 
    vector<vector<int>> edges = {{0, 2}, {2, 1}, {1, 0}, {0, 3}, {3, 4}}; // Edges
    
    vector<vector<int>> sccs = findSCCs(V, edges);
    
    cout << "Strongly Connected cmps:\n";
    for (auto &cmp : sccs) {
        for (int node : cmp) {
            cout << node << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
