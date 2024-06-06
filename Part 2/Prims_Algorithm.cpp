#include<bits/stdc++.h>
using namespace std;

#define frb(i, len) for(int i = len-1; i >= 0; i--)
#define fr(i, len) for(int i = 0; i < len; i++)
#define srt(a) sort(a.begin(),a.end())
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
typedef map<int,bool> mpib;
typedef map<int,int> mpii;
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

vector<pair<pair<int,int>,int>> CalculatePrimeMST(int n, int m, vector<pair<pair<int,int>,int>>& g) {
    unordered_map<int, list<pair<int,int>>>adj;
    for(int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vint key(n + 1);
    vector<bool> mst(n + 1);
    vint prnt(n + 1);

    fr(i, n + 1) {
        key[i] = INT_MAX;
        prnt[i] = -1;
        mst[i] = false;
    }
    
    key[0] = 0;
    prnt[1] = -1;

    for(int i = 1; i < n; i++) {
        int mn = INT_MAX;
        int u;
        for(int v = 1; v <= n; v += 1) {
            if(!mst[v] && key[v] < mn) {
                u = v;
                mn = key[v];
            }
        }
        mst[u] = true;

        for(auto i : adj[u]) {
            int v = i.first;
            int w = i.second;

            if(!mst[v] && w < key[v]) {
                prnt[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int,int>,int>> minSpanTree;
    for(int i = 2; i <= n; i++) {
        minSpanTree.push_back(make_pair(make_pair(prnt[i], i), key[i]));
    }
    return minSpanTree;
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<pair<pair<int,int>,int>> edges;
    cout << "Enter the edges in the format (u v weight):" << endl;
    for(int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back(make_pair(make_pair(u, v), weight));
    }

    vector<pair<pair<int,int>,int>> minSpanTree = CalculatePrimeMST(n, m, edges);

    cout << "Minimum Spanning Tree Edges:" << endl;
    for(auto edge : minSpanTree) {
        cout << edge.first.first << " " << edge.first.second << " " << edge.second << endl;
    }

    return 0;
}
