#include <bits/stdc++.h> 
using namespace std;
using namespace std;

const long long md = 1e9 + 7;

long long add(long long a, long long b) {
    return ((a % md) + (b % md)) % md;
}

long long prd(long long a, long long b) {
    return ((a % md) * (b % md)) % md;
}

long long solve(long long n, long long k) {
    vector<long long> dp(n+1,-1);

    dp[1] = k;
    dp[2] = add(k,prd(k,k-1));

    for (long long i = 3; i <= n; i++)
        dp[i] = prd(add(dp[i - 1], dp[i - 2]), k - 1);

    return dp[n];
}

long long numberOfWays(long long n, long long k) {
    return solve(n, k);
}

// long long solve(long long n, long long k, vector<long long>& dp) {
//     if (n == 1)
//         return k;
//     if (n == 2)
//         return add(k,prd(k, k - 1)); 
//     if (dp[n] != -1)
//         return dp[n];

//     dp[n] = prd(k - 1, add(solve(n - 1, k, dp), solve(n - 2, k, dp)));
//     return dp[n];
// }

// long long numberOfWays(long long n, long long k) {
//     vector<long long> dp(n + 1, -1);
//     return solve(n, k, dp);
// }

// long long solve(long long n, long long k) {
//     if (n == 1)
//         return k;
//     if (n == 2)
//         return add(k, prd(k, k - 1));
    
//     long long ans = add(prd(solve(n - 2, k), k - 1), prd(solve(n - 1, k), k - 1)); 
//     return ans;
// }

// long long numberOfWays(long long n, long long k) {
//     return solve(n, k);
// }