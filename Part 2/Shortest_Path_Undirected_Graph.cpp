#include <bits/stdc++.h>
using namespace std;

vector<int> shortest_path(vector<vector<int>>& adj, int source, int destination) {
    int n = adj.size();
    vector<int> parent(n, -1);  
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == destination) {
            break;  
        }

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = node;  
            }
        }
    }

   
    vector<int> path;
    int current = destination;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());

    return path;
}

int main() {
    vector<vector<int>> adj = {
        {1, 3},    // Node 0
        {0, 2, 4}, // Node 1
        {1, 5},    // Node 2
        {0},       // Node 3
        {1, 5},    // Node 4
        {2, 4}     // Node 5
    };

    int source = 0;
    int destination = 5;

    vector<int> shortest_path_result = shortest_path(adj, source, destination);

    if (shortest_path_result.empty()) {
        cout << "No path found between " << source << " and " << destination << endl;
    } else {
        cout << "Shortest path between " << source << " and " << destination << ": ";
        for (int node : shortest_path_result) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
