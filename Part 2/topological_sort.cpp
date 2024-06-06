#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& stk) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, stk);
        }
    }

    stk.push(node);
}

vector<int> topological_sort(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> stk;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, adj, visited, stk);
        }
    }

    vector<int> result;
    while (!stk.empty()) {
        result.push_back(stk.top());
        stk.pop();
    }

    return result;
}

int main() {
    vector<vector<int>> adj = {
        {},
        {2, 3},
        {4},
        {4, 5},
        {},
        {}
    };

    vector<int> sorted_order = topological_sort(adj);

    cout << "Topological Order:";
    for (int node : sorted_order) {
        cout << " " << node;
    }
    cout << endl;

    return 0;
}
