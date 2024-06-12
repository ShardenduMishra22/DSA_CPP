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

class Solution {
public:
    int solve(vector<int>& n, int trg) {
        vector<int> dp(trg + 1, 0);
        dp[0] = 1;        
        for (int i = 1; i <= trg; i++) {
            for (int j = 0; j < n.size(); j++) {
                if (i - n[j] >= 0) {
                    if (dp[i] > INT_MAX - dp[i - n[j]]) {
                        continue;
                    }
                    dp[i] += dp[i - n[j]];
                }
            }
        }
        return dp[trg];
    }

    int combinationSum4(vector<int>& n, int trg) {
        return solve(n, trg);
    }
};

// class Solution {
// public:
//     int solve(vector<int>& n, int trg, vector<int>& dp) {
//         if (trg < 0)
//             return 0;
        
//         if (trg == 0) 
//             return 1;
        
//         if (dp[trg] != -1) 
//             return dp[trg];
        
//         int ans = 0;
//         for (int i = 0; i < n.size(); i += 1) {
//             ans += solve(n, trg - n[i], dp);
//         }

//         dp[trg] = ans;
//         return dp[trg];
//     }

//     int combinationSum4(vector<int>& n, int trg) {
//         vector<int> dp(trg + 1, -1);
//         return solve(n, trg, dp);
//     }
// };


// class Solution {
// public:
//     int solve(vector<int>& n, int trg){
//         if(trg < 0)
//             return 0;
//         if(trg == 0)
//             return 1;
        
//         int ans = 0;
//         for(int i=0;i<n.size();i+=1){
//             ans += solve(n,trg - n[i]);
//         }
//         return ans;
//     }

//     int combinationSum4(vector<int>& n, int trg) {
//         return solve(n,trg);
//     }
// };