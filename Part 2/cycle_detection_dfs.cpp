#include<bits/stdc++.h>
using namespace std;
 
#define frb(i, len) for(int i = len-1; i >= 0; i--)
#define fr(i, len) for(int i = 0; i < len; i++)
#define tas cout<<"Tell a string : ";
#define all_v v.begin(), v.end()
#define YES cout<<"Yes \n";
#define No cout<<"No \n";
#define nl cout<<"\n";
#define MAX_SIZE 1000
#define pr protected
#define nptr nullptr
#define pv private
#define pb public
typedef priority_queue<long long,vector<long long>,greater<long long>> lprq_intd;
typedef priority_queue<int,vector<int>,greater<int>> prq_intd;
typedef vector<vector<string>> vvstr;
typedef priority_queue<int> prq_int;
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
template <typename T>
c_int MOD = 1e9 + 7;
c_int Mx_row = 100;
c_int Mx_col = 100;
int size_stack = 0;
int InvrsnCnt = 0;
int size_arr = 0;
int size_ll = 0;
int top = -1;

class Graph{
    unordered_map<int,list<int>> adj; 

public:
    void Add_Edge(int u,int v,bool dirn){
        adj[u].push_back(v);
        if(!dirn){
            adj[v].push_back(u);
        }
    }

    void PrntAdjList(){
        for(auto it : adj){
            cout<<it.first<<" -> ";
            for(auto it2 : it.second){
                cout<<it2<<",";
            }
            nl;
        }
    }

    bool isCyclic(int node,int parent,unordered_map<int,bool>&vis){
        vis[node] = true;
        for(auto neighbour : adj[node]){
            if(!vis[neighbour]){
                bool cycle = isCyclic(neighbour,node,vis);
                if(cycle){
                    return true;
                }
            }else if(neighbour != parent){
                return true;
            }
        }
        return false;
    }

    string CycleDetection(int n){
        unordered_map<int,bool> vis;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                bool ans = isCyclic(i, -1, vis);
                if(ans){
                    return "Yes";
                }
            }
        }
        return "No";
    }
};

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    Graph graph;
    cout << "Enter the edges (u, v):" << endl;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph.Add_Edge(u, v, false);
    }

    string result = graph.CycleDetection(n);
    cout << "Does the graph contain a cycle? " << result << endl;

    return 0;
}
