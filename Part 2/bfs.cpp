#include<bits/stdc++.h>
using namespace std;

#define frb(i, len) for(int i = len-1; i >= 0; i--)
#define fr(i, len) for(int i = 0; i < len; i++)
#define tas cout<<"Tell a string : ";
#define YES cout<<"Yes \n";
#define No cout<<"No \n";
#define nl cout<<"\n";
#define MAX_SIZE 1000
#define pr protected
#define nptr nullptr
#define pv private
#define pb public
typedef vector<vector<string>> vvstr;
typedef vector<vector<int>> vvint;
typedef vector<string> vstr;
typedef vector<int> vint;
typedef long long int ll;
typedef stack<int> sint;
typedef queue<int> qint;
typedef deque<ll> dllnt;
typedef const int c_int;
typedef vector<ll> vll;
typedef double dbl;
c_int MOD = 1e9 + 7;
c_int Mx_row = 100;
c_int Mx_col = 100;
int size_stack = 0;
int InvrsnCnt = 0;
int size_arr = 0;
int size_ll = 0;
int top = -1;

template <typename T>
class graph {
public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool dirn) {
        adj[u].push_back(v);
        if (dirn)
            adj[v].push_back(u);
    }

    void prntAdjList() {
        for (auto i : adj) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << j << " ";
            }
            nl;
        }
    }

    
    void bfs(unordered_map<int, set<int>>& adjList, unordered_map<int, bool>& visited, vector<int>& ans, int node) {
        visited[node] = true;
        
        queue<int> q;
        q.push(node);
        while (!q.empty()) {
            int frntNode = q.front();
            q.pop();
            ans.push_back(frntNode);
            for (auto i : adjList[frntNode]) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    vector<int> BFS(int vertex, vector<pair<int, int>> edges) {
        unordered_map<int, set<int>> adjList;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i].first;
            int v = edges[i].second;

            adjList[u].insert(v);
            adjList[v].insert(u);
        }

        unordered_map<int, bool> visited;
        vector<int> ans;

        for (int i = 0; i < vertex; i++) {
            if (!visited[i]) {
                bfs(adjList, visited, ans, i);
            }
        }
        return ans; 
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    graph<int> g;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 1);
    }
    g.prntAdjList();

    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    vector<int> result = g.BFS(4, edges);
    for (int i : result) {
        cout << i << " ";
    }
    nl;

    return 0;
}
