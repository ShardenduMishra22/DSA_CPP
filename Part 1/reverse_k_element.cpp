#include <bits/stdc++.h>
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
typedef deque<long long> dllnt;
typedef vector<int> vint;
typedef long long int ll;
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

void reverse1(int k, qint& q){
    sint a;
    for(int i = 0; i < k;i++){
        int temp = q.front();
        q.pop();
        a.push(temp);
    }
    while(!a.empty()){
        int temp = a.top();
        a.pop();
        q.push(temp);
    }
    int t = q.size() - k;
    while(t--){
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}


int main(){
    qint q1,q;
    vint a;
    q1.push(4);
    q1.push(1);
    q1.push(9);
    q1.push(0);
    q1.push(3);

    q.push(4);
    q.push(1);
    q.push(9);
    q.push(0);
    q.push(3);
    cout<<"The original queue : ";
    while(!q1.empty()){
        cout<<q1.front()<<" ";
        q1.pop();
    }
    nl;
    int k = 3;
    reverse1(k,q);
    cout<<"The reversed queue : ";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    nl; 
}
