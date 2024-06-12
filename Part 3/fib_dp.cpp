#include <bits/stdc++.h>
using namespace std;

#define frb(i, len) for(int i = len-1; i >= 0; i--)
#define fr(i, len) for(int i = 0; i < len; i++)

#define rvrs(a) reverse(a.begin(), a.end())
#define srt(a) sort(a.begin(), a.end())

#define YES cout << "Yes \n";
#define NOO cout << "No  \n";
#define nl cout << "\n";

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

int fib(int n) {
    if (n == 1 || n == 0) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int DPfib(int n, vint &dp) {
    if (n == 1 || n == 0) {
        return n;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    dp[n] = DPfib(n - 1, dp) + DPfib(n - 2, dp);
    return dp[n];
}

int dp_fib(int n) {

    vint dp(n + 1);
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

int dpSpc_fib(int n) {
    
    int curr, prev1 = 1, prev2 = 0;

    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

int main() {
    fast();
    int n = 6;
    cout << fib(n) << "\n";

    cin >> n;
    vint dp(n + 1, -1);
    cout << DPfib(n, dp) << "\n";

    cout << dp_fib(6) << "\n";

    cout << dpSpc_fib(6) << "\n";

    return 0;
}
