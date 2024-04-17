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

template <typename T>
class Graph{
    unordered_map<T,list<T>> adj;

public:
    void Add_Edge(T u,T v,bool dirn){
        // undirected = 0; (Direction)
        // directed   = 1; (Direction)
        
        //create an edge from u to v
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
};

int main(){
    Graph<int> g; 
    g.Add_Edge(1,2,false);
    g.Add_Edge(1,3,false);
    g.Add_Edge(2,3,true);
    g.Add_Edge(3,4,true);
    g.Add_Edge(4,5,true);
    g.PrntAdjList();

    return 0;
}
