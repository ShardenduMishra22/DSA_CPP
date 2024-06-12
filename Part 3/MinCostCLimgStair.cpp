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

typedef stringstream strgm;
typedef long long int ll;
typedef const int c_int;
typedef unsigned unsg;
typedef double dbl;

typedef vector<vector<string>> vvstr;
typedef vector<vector<bool>> vvbol;
typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvll;

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

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// ALL WRONG
// // Recursion 
// // // one way
// // // int solve(ll n,ll i){
// // //     if(i == n){
// // //         return 1;
// // //     }
// // //     if(i > n){
// // //         return 0;
// // //     }
// // //     return (solve(n,i+1) + solve(n,i+2))%MOD;
// // // }
// // // int solve(ll n){
// // //     if(n <= 1){
// // //         return n;
// // //     }
// // //     return solve(n-1) + solve(n-2);
// // // }
// // Top Down
// // // int dp_top_down(ll n,vint& dp){
// // //     if(n == 0 || n == 1){
// // //         return n; 
// // //     }
// // //     if(dp[n] != -1){
// // //         return dp[n];
// // //     }
// // //     dp[n] = dp_top_down(n-1,dp) + dp_top_down(n-2,dp);
// // //     return dp[n];
// // // }
// // Bottom Top
// // // int btm_up(ll n){
// // //     vint dp;
// // //     dp[0] = 0;
// // //     dp[1] = 1;
// // //     for(int i=2;i<=n;i++){
// // //         dp[i] = dp[i-1] + dp[i-2];
// // //     }
// // //     return dp[n];
// // // }
// // Space Optimisation
// // // int SpcOptm(ll n){
// // //     int p1 = 1 ,p2 = 0,cr;
// // //     for(int i=2;i<=n;i++){
// // //         cr = p1 + p2;
// // //         p1 = p2;
// // //         p1 = cr;
// // //     }
// // //     return cr;
// // // }

int solve1(int n,vint& cost){
    if(n == 0 || n == 1){
        return cost[n];
    }
    int ans = cost[n] + min(solve1(n-1,cost),solve1(n-2,cost));
    return ans;
}

int MinCost1(int n,vint& cost){
    int n = cost.size();
    return min(solve1(n-1,cost),solve1(n-2,cost));
}

////////////////////////////////////////////////////////////////

int solve2(int n,vint& cost,vint& dp){
    if(n == 0 || n == 1){
        return cost[n];
    }
    if(dp[n] != -1){
        return dp[n]; 
    }
    dp[n] = min(solve2(n-1,cost,dp),solve2(n-2,cost,dp));
    return dp[n];
}

int MinCost2(int n,vint& cost){
    int n = cost.size();
    vint dp(n+1,-1);
    return min(solve2(n-1,cost,dp),solve2(n-2,cost,dp));
}

////////////////////////////////////////////////////////////////

int solve3(int n,vint& cost){
    vint dp(n+1);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i=2;i<n;i++){
        dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]);
}

int MinCost3(int n,vint& cost){
    int n = cost.size();
    solve3(n,cost);
}

/////////////////////////////////////////////////////////////////

int solve4(int n,vint& cost){

    int p1 = cost[0];
    int p2 = cost[1];
    int curr;

    for(int i=2;i<=n;i++){
        curr = cost[i] + min(p1,p2);
        p2 = p1;
        p1 = curr;
    }
    return min(p1,p2);
}

int MinCost(int n,vint& cost){
    int n = cost.size();
    solve3(n,cost);
}

int main(){
    fast();
}