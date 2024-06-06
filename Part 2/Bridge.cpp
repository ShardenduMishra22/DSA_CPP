#include <bits/stdc++.h>
using namespace std;

#define frb(i, len) for(int i = len-1; i >= 0; i--)
#define fr(i, len) for(int i = 0; i < len; i++)

#define rvrs(a) reverse(a.begin(),a.end())
#define srt(a) sort(a.begin(),a.end())

#define YES cout<<"Yes \n";
#define NOO cout<<"No  \n";
#define nl cout<<"\n";

#define MAX_SIZE 10000
#define nptr nullptr
#define NULL NL

typedef stringstream strgm;
typedef long long int ll;
typedef const int c_int;
typedef unsigned unsg;
typedef double dbl;

typedef vector<vector<string>> vvstr;
typedef vector<vector<bool>> vvint;
typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvint;

typedef vector<string> vstr;
typedef vector<int> vint;
typedef vector<bool> vbl;
typedef vector<ll> vll;

typedef stack<string> sstr;
typedef stack<bool> sbl;
typedef stack<int> sint;
typedef stack<ll> sll;

typedef queue<string> qstr;
typedef queue<bool> qbl;
typedef queue<int> qint;
typedef queue<ll> qll;

c_int MOD = 1e9 + 7;
c_int Mx_row = 100;
c_int Mx_col = 100;
int size_stack = 0;
int InvrsnCnt = 0;
int size_arr = 0;
int size_ll = 0;
int top = -1;

void dfs(int u, int prnt, int &tmr, vint &disc, vint &low, vvint &result, unordered_map<int, list<int>> &adj) {
    static unordered_map<int, bool> vis;
    vis[u] = true;
    disc[u] = low[u] = ++tmr;
    
    for(auto v : adj[u]) {
        if (v == prnt){
            continue;
        }
        if(!vis[v]) {
            dfs(v, u, tmr, disc, low, result, adj);
            low[u] = min(low[u], low[v]);
            
            if (low[v] > disc[u]) {
                result.push_back({u, v});
            }
        
        }else if (v != prnt) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

vvint FindBrdg(vvint &edg, int V, int e) {
    unordered_map<int, list<int>> adj;
    fr(i, edg.size()) {
        int u = edg[i][0];
        int v = edg[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int tmr = 0;
    vint disc(V, -1);
    vint low(V, -1);
    vvint result;

    fr(i, V) {
        if (disc[i] == -1) {
            dfs(i, -1, tmr, disc, low, result, adj);
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vvint edges = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    int vertices = 4;
    int edges_count = edges.size();

    vvint bridges = FindBrdg(edges, vertices, edges_count);

    for (const auto &bridge : bridges) {
        cout << bridge[0] << " - " << bridge[1] << "\n";
    }

    return 0;
}