#include<bits/stdc++.h>
using namespace std;

#define frb(i, len) for(int i = len-1; i >= 0; i--)
#define fr(i, len) for(int i = 0; i < len; i++)
#define srt(a) sort(a.begin(),a.end())
#define tas cout<<"Tell a string : ";
#define unop unordered_map
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


vint djkstra(vvint& vec,int vertex,int edg,int src){
    unop<int,list<pair<int,int>>> adj;
    for(int i=0;i<edg;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(u,w));
        adj[v].push_back(make_pair(v,w));
    }

    vint dist(vertex);
    
    for(int i=0;i<vertex;i++){
        dist[i] = INT_MAX;
    }

    set<pair<int,int>> st;
    dist[src] = 0;
    st.insert(make_pair(0,src));

    while(!st.empty()){
        auto top = *(st.begin());

        int NodeDist = top.first;
        int TopNode = top.second;

        st.erase(st.begin());

        for(auto i:adj[TopNode]){
            if(NodeDist + i.second < dist[i.first]){
                auto record = st.find(make_pair(dist[i.first],i.first));
                if(record != st.end()){
                    st.erase(record);
                }
                dist[i.first] = NodeDist + i.second;
                st.insert(make_pair(dist[i.first],i.first));
            }
        }

    }
        
}