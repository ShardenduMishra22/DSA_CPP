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
#define N 1000
typedef vector<vector<string>> vvstr;
typedef vector<vector<int>> vvint;
typedef vector<string> vstr;
typedef stack<int> sint;
typedef queue<int> qint;
typedef deque<ll> dllnt;
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

void reverse1(qint& a){
    sint b;
    while(!a.empty()){
        b.push(a.front());
        a.pop();
    }
    while(!b.empty()){
        a.push(b.top());
        b.pop();
    }
}

void reverse2(qint& a){
    if(a.empty()){
        return ;
    }
    int b = a.front();
    a.pop();
    reverse2(a);
    a.push(b);
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "Original Queue: ";
    queue<int> original = q;
    while (!original.empty()) {
        cout << original.front() << " ";
        original.pop();
    }
    cout << endl;

    reverse2(q);

    cout << "Reverse1d Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}