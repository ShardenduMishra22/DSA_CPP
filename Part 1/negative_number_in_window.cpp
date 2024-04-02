#include<bits/stdc++.h>
using namespace std;

#define frb(i, len) for(int i = len-1; i >= 0; i--)
#define fr(i, len) for(int i = 0; i < len; i++)
#define tas cout<<"Tell a string : ";
#define nl cout<<"\n";
#define nptr nullptr
#define pr protected
#define pv private
#define pb public
#define MAX_SIZE 1000
typedef vector<vector<string>> vvstr;
typedef vector<vector<int>> vvint;
typedef vector<string> vstr;
typedef stack<int> sint;
typedef vector<long long> vll;
typedef queue<int> qint;
typedef deque<ll> dllnt;
typedef vector<int> vint;
typedef ll ll;
typedef const int c_int;
typedef double dbl;
int InversionCount = 0;
int size_stack = 0;
int size_arr = 0;
int size_ll = 0;
int top = -1;
c_int MOD = 1e9 + 7;
c_int Mx_row = 100;
c_int Mx_col = 100;

vll printFirstNegativeInteger(ll A[], ll N,ll K) {
    deque<ll> dq; 
    vll ans;   
    int negative = -1; 

    for (int i = 0; i < K; i++) {
        if (A[i] < 0){
            dq.push_back(i);
        }
    }

    if(!dq.empty()) {
        ans.push_back(A[dq.front()]);
    }else{
        ans.push_back(0);   
    }

    for (int i = K; i < N; i++) {
        // Pop out of window element
        if (!dq.empty() && (i - dq.front()) >= K) {
            dq.pop_front();
        }

        if (A[i] < 0) {
            dq.push_back(i);
        }

        if (!dq.empty()) {
            ans.push_back(A[dq.front()]);
        } else {
            ans.push_back(0);
        }
    }
    return ans;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        ll k;
        cin >> k;

        vll ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
