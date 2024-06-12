#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
static auto _ = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

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
typedef vector<vector<bool>> vvbl;
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
    static bool comp(pair<int,int> a, pair<int,int> b) {
        return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n) {
        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back(make_pair(start[i], end[i]));
        }
        sort(v.begin(), v.end(), comp);
        int cnt = 1;
        int last_end_time = v[0].second;
        for (int i = 1; i < n; i++) {
            if (v[i].first > last_end_time) {
                cnt++;
                last_end_time = v[i].second;
            }
        }
        return cnt;
    }
};