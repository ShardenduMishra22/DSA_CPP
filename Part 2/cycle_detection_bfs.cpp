#include<bits/stdc++.h>
using namespace std;

class Graph{
    unordered_map<int, list<int>> adj;

public:
    void Add_Edge(int u, int v, bool dirn){
        adj[u].push_back(v);
        if(!dirn){
            adj[v].push_back(u);
        }
    }

    bool isCyclic(){
        unordered_map<int, bool> vis;
        unordered_map<int, int> parent;

        for(auto& it : adj){
            if(!vis[it.first]){
                queue<int> q;
                q.push(it.first);
                vis[it.first] = true;
                parent[it.first] = -1;
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    for(auto& v : adj[u]){
                        if(!vis[v]){
                            vis[v] = true;
                            q.push(v);
                            parent[v] = u;
                        }else if(parent[u] != v){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

};

int main(){
    Graph g;
    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {1, 4}, {2, 7}, {2, 6}, {2, 3}, {3, 4}, {3, 6}, {4, 5}, {5, 6}, {6, 7}, {7, 8}};
    for(auto& edge : edges){
        g.Add_Edge(edge.first, edge.second, false); 
    }

    if(g.isCyclic()){
        cout << "Yes, the graph contains a cycle." << endl;
    } else {
        cout << "No, the graph does not contain a cycle." << endl;
    }

    return 0;
}