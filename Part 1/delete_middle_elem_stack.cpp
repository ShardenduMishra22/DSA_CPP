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
typedef vector<int> vint;
typedef long long int ll;
typedef const int c_int;
typedef double dbl;
int InversionCount = 0;
int size_stack = 0;
int size_ll = 0;
int size_arr = 0;
int top_st = -1;
c_int MOD = 1e9 + 7;
c_int Mx_row = 100;
c_int Mx_col = 100;

void rmv_middle(stack<int>& st,int& count){
    if(st.empty() || size_stack/2 == count){
        st.pop();
        size_stack -= 1;
        return ;
    }
    int temp = st.top();
    st.pop();

    count = count + 1;
    rmv_middle(st,count);
    st.push(temp);
    return;
}

int main(){
    stack<int>st;
    fr(i,5){
        int a; cin>>a;
        st.push(a);
        size_stack += 1;
    }
    int count = 0;
    rmv_middle(st,count);
    fr(i,size_stack){
        cout<<st.top();
        st.pop();
    }
}