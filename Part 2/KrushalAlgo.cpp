#include <bits/stdc++.h>
using namespace std;

#define frb(i, len) for(int i = len-1; i >= 0; i--)
#define fr(i, len) for(int i = 0; i < len; i++)

#define rvrs(a) reverse(a.begin(),a.end())

#define srt(a) sort(a.begin(),a.end())

#define YES cout<<"Yes \n";
#define NOO cout<<"No  \n";
#define nl cout<<"\n";

#define unordered_map unmp
#define MAX_SIZE 10000
#define nptr nullptr
#define NULL NL
#define map mp

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

void Make_set(vint& prnt, vint& rank, int n) {
    for (int i = 0; i < n; ++i) {
        prnt[i] = i;
        rank[i] = 0;
    }
}

int FindPrnt(vint& prnt, int node) {
    if (prnt[node] != node) {
        prnt[node] = FindPrnt(prnt, prnt[node]);
    }
    return prnt[node];
}

void UnionSet(int u, int v, vint& prnt, vint& rank) {
    int u = FindPrnt(prnt, u);
    int v = FindPrnt(prnt, v);

    if (u != v) {
        if (rank[u] > rank[v]) {
            prnt[v] = u;
        } else if (rank[u] < rank[v]) {
            prnt[u] = v;
        } else {
            prnt[v] = u;
            rank[u] += 1;
        }
    }
}

// Kruskal's algorithm using Union-Find
int MinSpnTree(vvint& edgs, int n) {
    srt(edgs);
    vint prnt(n);
    vint rank(n);

    Make_set(prnt,rank,n);
    int mnw = 0;
    fr(i,edgs.size()){
        int u = FindPrnt(prnt,edgs[i][0]);
        int v = FindPrnt(prnt,edgs[i][1]);
        int w = edgs[i][2];

        if(u != v){
            mnw += w;
            UnionSet(u,v,prnt,rank);
        }
    }
    return mnw;
}
