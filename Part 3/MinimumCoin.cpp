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


class Solution {
public:
    int solve(vector<int>& coins, int amount){
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        } 
        
        if (dp[amount] == INT_MAX) {
            return -1;
        }
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins, amount);

        if (ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};


// Top Down
// class Solution {
// public:
//     int solve(vector<int>& coins,int amt,vector<int>& dp){
//         if(amt == 0){
//             return 0;
//         }
//         if(amt < 0){
//             return INT_MAX;
//         }
//         if(dp[amt] != -1){
//             return dp[amt];
//         }
//         int mn = INT_MAX;
//         for(int i=0;i<coins.size();i++){
//             int ans = solve(coins,amt-coins[i],dp);
//             if(ans != INT_MAX){
//                 mn = min(mn,1+ans);
//             }
//         }
//         dp[amt] = mn;
//         return dp[amt];
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         vector<int> dp(amount+1,-1);
//         int ans = solve(coins,amount,dp);

//         if(ans == INT_MAX){
//             return -1;
//         }
//         return ans;
//     }
// };

// Recursion
// class Solution {
// public:
//     int solve(vector<int>& coins,int amt){
//         if(amt == 0){
//             return 0;
//         }
//         if(amt < 0){
//             return INT_MAX;
//         }

//         int mn = INT_MAX;
//         for(int i=0;i<coins.size();i++){
//             int ans = solve(coins,amt-coins[i]);
//             if(ans != INT_MAX){
//                 mn = min(mn,1+ans);
//             }
//         }
//         return mn;
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         int ans = solve(coins,amount);

//         if(ans == INT_MAX){
//             return -1;
//         }
//         return ans;
//     }
// };