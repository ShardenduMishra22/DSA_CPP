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
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int prev2 = 0;
        int prev1 = nums[0];
        
        for (int i = 1; i < n; ++i) {
            int current = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};

// class Solution {
// public:
//     int solve(vector<int>& nums) {
//         int n = nums.size();
        
//         vector<int> dp(n);
//         dp[0] = nums[0];
//         if (n > 1) {
//             dp[1] = max(nums[0], nums[1]);
//         }
        
//         for (int i = 2; i < n; ++i) {
//             dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
//         }
        
//         return dp[n-1];
//     }

//     int rob(vector<int>& nums) {
//         return solve(nums);
//     }
// };

// class Solution {
// public:
//     int solve(vector<int>nums,int n,vector<int>& dp){
//         if(n < 0)
//             return 0;
//         if(n == 0)
//             return nums[0];
//         if(dp[n] != INT_MAX)
//             return dp[n];
        
//         int inc = solve(nums,n-2,dp) + nums[n];
//         int exc = solve(nums,n-1,dp) + 0;

//         dp[n] = max(inc,exc);
//         return dp[n];
//     }

//     int rob(vector<int>& n) {
//         int i=n.size();
//         vector<int> dp(i+1,INT_MAX);
//         int ans = solve(n,i-1,dp);
//         return ans;
//     }
// };

// class Solution {
// public:
//     int solve(vector<int>nums,int )i{
//         if(i < 0)
//             return 0;
//         if(i == 0)
//             return nums[0];

//         return max(solve(nums,i-2)+nums[i]
//                   ,solve(nums,i-1));
//     }

//     int rob(vector<int>& n) {
//         int i=n.size();
//         int ans = solve(n,i-1);
//         return ans;
//     }
// };

int main(){
    fast();
    int n=9;
    vint ans(n);
    fr(i,n){
        ans.push_back(i);
    }

    vint res(ans);
    fr(i,n){
        cout<<res[i];
    }
}