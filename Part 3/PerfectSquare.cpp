#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MinSquares(int n) {
    
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i * i <= j; ++i) {
                int temp = i*i;
                dp[j] = min(dp[j], dp[j - temp] + 1);
            }
        }
        
        return dp[n];
    }
};


// class Solution {
// public:
//     int solve(int n, vector<int>& dp) {
//         if (n == 0 || n == 1) {
//             return n;
//         }
//         if (dp[n] != -1) {
//             return dp[n];
//         }
        
//         int ans = INT_MAX;
//         for (int i = 1; i * i <= n; i++) {
//             int temp = i * i;
//             ans = min(ans, solve(n - temp, dp) + 1);
//         }
//         dp[n] = ans;
//         return dp[n];
//     }

//     int MinSquares(int n) {
//         vector<int> dp(n + 1, -1);
//         return solve(n, dp);
//     }
// };

// class Solution {
// public:
//     int solve(int n) {
//         if (n == 0 || n == 1) {
//             return n;
//         }
        
//         int ans = INT_MAX;
//         for (int i = 1; i * i <= n; i++) {
//             int temp = i * i;
//             ans = min(ans, solve(n - temp) + 1);
//         }
//         ans;
//         return ans;
//     }

//     int MinSquares(int n) {
//         return solve(n);
//     }
// };