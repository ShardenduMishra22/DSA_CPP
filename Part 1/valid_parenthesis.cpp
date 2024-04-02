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
int size_stack= 0;
int size_arr = 0;
int size_ll = 0;
int top = -1;
c_int MOD = 1e9 + 7;
c_int Mx_row = 100;
c_int Mx_col = 100;

bool chck_stack(stack<char>& st, string& str) {
    if (str.empty()) return true;
    for (char c : str) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) {
                return false;  // Closing parenthesis encountered without a corresponding opening parenthesis
            }
            char top_char = st.top();
            st.pop();
            if ((c == ')' && top_char != '(') ||
                (c == ']' && top_char != '[') ||
                (c == '}' && top_char != '{')) {
                return false;  // Mismatched closing parenthesis
            }
        }
    }
    return st.empty();  // Return true if stack is empty at the end (all parentheses matched)
}

int main(){
    stack<char> st ;
    string stk = "{[({[({})]})]}";
    if(chck_stack(st,stk)){
        cout<<"Parantehsis check passed!";
        nl;
    }else{
        cout<<"Parantehsis check failed!";
        nl;
    }
}