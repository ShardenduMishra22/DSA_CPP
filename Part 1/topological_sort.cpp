#include <bits/stdc++.h>
using namespace std;

#define frb(i, len) for(int i = len-1; i >= 0; i--)
#define fr(i, len) for(int i = 0; i < len; i++)
#define tas cout<<"Tell a string : ";
#define all_v v.begin(), v.end()
#define YES cout<<"Yes \n";
#define No cout<<"No \n";
#define nl cout<<"\n";
#define MAX_SIZE 1000

typedef vector<vector<int>> vvint;

void topo(int node, unordered_map<int,bool>& vis, stack<int>& s, unordered_map<int,list<int>>& adj){
    vis[node] = true;
    for(auto neighbour : adj[node]){
        if(!vis[neighbour]){
            topo(neighbour, vis, s, adj);
        }
    }
    s.push(node);
}

vector<int> TopologicalSort(vvint& edges, int vertex, int e){
    unordered_map<int,list<int>> adj;
    for(int i = 0; i < e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    unordered_map<int,bool> vis;
    stack<int> s;
    for(int i = 0; i < vertex; i++){
        if(!vis[i]){
            topo(i, vis, s, adj);
        }
    }

    vector<int> result;
    while(!s.empty()){
        result.push_back(s.top());
        s.pop();
    }
    return result;
}

int main(){
    int vertex = 6;
    int e = 6;
    vvint edges = {{5, 0}, {4, 0}, {4, 1}, {5, 2}, {2, 3}, {3, 1}};

    vector<int> sorted = TopologicalSort(edges, vertex, e);

    cout << "Topological sorting order: ";
    for(int node : sorted){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}