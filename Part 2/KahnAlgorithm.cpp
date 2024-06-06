#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topological_sort(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> indegree(n, 0);
    queue<int> q;
    vector<int> result;

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
        result.push_back(node);

        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (result.size() != n) {
        result.clear();
    }

    return result;
}

int main() {
    vector<vector<int>> adj = {
        {1, 3},    
        {2},       
        {4},       
        {5},       
        {6},       
        {6},       
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
