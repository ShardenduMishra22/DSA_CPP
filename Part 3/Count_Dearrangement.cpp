#include <bits/stdc++.h>
using namespace std;

const long long md = 10e9 + 7;
long long solve(int n){
    long long ans;
    long long p2 = 0;
    long long p1 = 1;

    for(int i = 3; i <= n; i++){
        ans = ((i-1) * (p2%md + p1%md)) % md;
        p2 = p1;
        p1 = ans;
    }
    return p1;
}

long long countDerangements(int n) {
    return solve(n);
}

// long long solve(int n){
//     vector<long long> dp(n+1,INT_MIN);
//     dp[1] = 0;
//     dp[2] = 1;

//     for(int i = 3; i <= n; i++){
//         dp[i] = ((i-1) * (dp[i-1] + dp[i-2])) % md;
//     }
//     return dp[n];
// }

// long long countDerangements(int n) {
//     return solve(n);
// }

// long long solve(int n, vector<long long>& dp){
//     if (n == 1) 
//         return 0;
//     if (n == 2) 
//         return 1;
//     if (dp[n] != -1)
//         return dp[n];

//     dp[n] = ((n-1) * (solve(n-1, dp) + solve(n-2, dp)) % md) % md;
//     return dp[n];
// }

// long long countDerangements(int n) {
//     vector<long long> dp(n+1, -1);
//     return solve(n, dp);
// }

// long long countDerangements(int n) {
//     if (n == 1) 
//         return 0;
//     if (n == 2) 
//         return 1;
    
//     return ((n-1)*(countDerangements(n-1)%md + countDerangements(n-2)%md))% md;
// }