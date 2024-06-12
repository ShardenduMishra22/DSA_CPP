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

int solve(vint& wgt, vint& val, int n, int cap) {
    vint curr(cap+1,0);
    vint prev(cap+1,0);

    for (int w = 0; w <= cap; ++w) {
        if (wgt[0] <= w) {
            prev[w] = val[0];
        } else {
            prev[w] = 0;
        }
    }

    for (int idx = 1; idx < n; ++idx) {
        for (int w = 0; w <= cap; ++w) {
            int inc = 0;
            if (wgt[idx] <= w) {
                inc = val[idx] + prev[w - wgt[idx]];
            }
            int exc = prev[w - wgt[idx]];
            curr[w] = max(inc, exc);
        }
        prev = curr;
    }

    return prev[cap];
}

int knapsack(vint wgt, vint val, int n, int mxwg) {
    return solve(wgt, val, n, mxwg);
}

// int solve(vint& wgt, vint& val, int n, int cap) {
//     vvint dp(n, vint(cap + 1, 0));
//     for (int w = 0; w <= cap; ++w) {
//         if (wgt[0] <= w) {
//             dp[0][w] = val[0];
//         } else {
//             dp[0][w] = 0;
//         }
//     }
//     for (int idx = 1; idx < n; ++idx) {
//         for (int w = 0; w <= cap; ++w) {
//             int inc = 0;
//             if (wgt[idx] <= w) {
//                 inc = val[idx] + dp[idx - 1][w - wgt[idx]];
//             }
//             int exc = dp[idx - 1][w];
//             dp[idx][w] = max(inc, exc);
//         }
//     }
//     return dp[n - 1][cap];
// }
// int knapsack(vint wgt, vint val, int n, int mxwg) {
//     return solve(wgt, val, n, mxwg);
// }

// int solve(vint& wgt,vint& val,int idx,int cap,vvint& dp){
//     if(idx == 0){
//         if(wgt[0] <= cap){
//             return wgt[0];
//         }else{
//             return 0;
//         }
//     }
//     if(dp[idx][cap] != -1){
//         return dp[idx][cap];
//     }

//     int inc;
//     if(wgt[idx] <= cap){
//         inc = val[idx] + solve(wgt,val,idx-1,cap-wgt[idx],dp); 
//     }
//     int exc = 0 + solve(wgt,val,idx-1,cap,dp);

//     dp[idx][cap] = max(inc,exc);
//     return dp[idx][cap];
// }

// int knapsack(vint wgt,vint val,int n,int mxwg){
//     vvint dp(n,vint (mxwg + 1,0));
//     return solve(wgt,val,n-1,mxwg,dp);
// }

// int solve(vint& wgt,vint& val,int idx,int cap){
//     if(idx == 0){
//         if(wgt[0] <= cap){
//             return wgt[0];
//         }else{
//             return 0;
//         }
//     }
//     int inc;
//     if(wgt[idx] <= cap){
//         inc = val[idx] + solve(wgt,val,idx-1,cap-wgt[idx]); 
//     }
//     int exc = 0 + solve(wgt,val,idx-1,cap);

//     int ans = max(inc,exc);
//     return ans;
// }

// int knapsack(vint wgt,vint val,int n,int mxwg){
//     return solve(wgt,val,n-1,mxwg);
// }


int main(){
    fast();
}