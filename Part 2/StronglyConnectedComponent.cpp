#include <bits/stdc++.h>
using namespace std;

#define fr(i, len) for(int i = 0; i < len; i++)

typedef vector<int> vint;
typedef vector<vector<int>> vvint;

void dfs(int node, vector<bool> &visited, stack<int> &st, vector<vector<int>> &adj) {
    visited[node] = true;
    for (int neighbour : adj[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour, visited, st, adj);
        }
    }
    st.push(node);
}

void reverseDfs(int node, vector<bool> &visited, vector<vector<int>> &transpose, vint &component) {
    visited[node] = true;
    component.push_back(node);
    for (int neighbour : transpose[node]) {
        if (!visited[neighbour]) {
            reverseDfs(neighbour, visited, transpose, component);
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
    vector<bool> visited(V, false);
    
    fr(i, V) {
        if (!visited[i]) {
            dfs(i, visited, st, adj);
        }
    }
    
    fr(i, V) {
        for (int neighbour : adj[i]) {
            transpose[neighbour].push_back(i);
        }
    }
    
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> sccs;
    
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        
        if (!visited[node]) {
            vint component;
            reverseDfs(node, visited, transpose, component);
            sccs.push_back(component);
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
    
    cout << "Strongly Connected Components:\n";
    for (auto &component : sccs) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
