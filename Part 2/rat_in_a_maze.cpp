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
typedef vector<vector<bool>> vvbl;
typedef vector<string> vstr;
typedef vector<int> vint;
typedef vector<bool> vbl;
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

bool isSafe(int newx,int newy,vvbl& vis,vvint& arr,int n){
    if((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && (vis[newx][newy] != 1) && (arr[newx][newy] == 1)){
        return true;
    }
    return false;
}

void solve(int x,int y,vvint& arr,int n,vstr& ans,vvbl& vis,string path){
    if(x == n - 1 && y == n - 1){
        ans.push_back(path);
        return;
    }
    // D L R U
    vis[x][y] = 1;
    if (isSafe(x+1,y,vis,arr,n)){
        solve(x+1,y,arr,n,ans,vis,path + 'D');
    }
    
    if (isSafe(x,y-1,vis,arr,n)){
        solve(x,y-1,arr,n,ans,vis,path + 'L');
    }
    
    if (isSafe(x,y+1,vis,arr,n)){
        solve(x,y+1,arr,n,ans,vis,path + 'R');
    }
    
    if (isSafe(x-1,y,vis,arr,n)){
        solve(x-1,y,arr,n,ans,vis,path + 'U');
    }
    vis[x][y] = 0;
}

vstr SearchMaze(vvint& arr,int n){
    vstr ans;
    vvbl vis(n,vbl(n,0));
    string path = "";
    if(!arr[0][0]){
        return ans;
    }
    solve(0,0,arr,n,ans,vis,path);
    return ans;
}

int main() {
    int n;
    cout << "Enter the size of the maze: ";
    cin >> n;

    vvint arr(n, vint(n));
    cout << "Enter the maze matrix (0s for blocked cells, 1s for open cells):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }

    vstr paths = SearchMaze(arr, n);

    cout << "Possible paths to reach the bottom-right corner:\n";
    for (const string& path : paths) {
        cout << path << endl;
    }

    return 0;
}
