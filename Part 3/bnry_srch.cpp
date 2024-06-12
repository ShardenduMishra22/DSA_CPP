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

int main() {

    vector<int> ans = {1, 2, 5, 7, 9};

    int val = 3;


    auto lb = lower_bound(ans.begin(), ans.end(), val);
    cout << "lower_bound: " << (lb - ans.begin()) << endl;


    auto ub = upper_bound(ans.begin(), ans.end(), val);
    cout << "upper_bound: " << (ub - ans.begin()) << endl;


    bool found = binary_search(ans.begin(), ans.end(), val);
    cout << "binary_search: " << found << endl;


    auto er = equal_range(ans.begin(), ans.end(), val);
    cout << "equal_range: [" << (er.first - ans.begin()) << ", " << (er.second - ans.begin()) << ")" << endl;

    return 0;
}
