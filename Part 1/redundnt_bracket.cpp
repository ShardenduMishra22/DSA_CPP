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
int size_arr = 0;
int size_ll = 0;
int top = -1;
c_int MOD = 1e9 + 7;
c_int Mx_row = 100;
c_int Mx_col = 100;

inline bool isOpr(char ch){
    if(ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '(' ) return true;
    return false;
}

bool redundant_bracket(string& s){
    stack<char> st;
    for(char ch : s){
        if(ch == '(' || isOpr(ch)){
            st.push(ch);
        } else if(ch == ')') {
            bool hasOperator = false;
            while(!st.empty() && st.top() != '('){
                if(isOpr(st.top())) {
                    hasOperator = true;
                }
                st.pop();
            }
            st.pop(); // Pop '('
            if(hasOperator == false) {
                return true; // Redundant bracket found
            }
        }
    }
    return false; // No redundant brackets found
}
int main(){
    string str = "(a + (b + c))";
    if(!redundant_bracket(str)){
        cout<<"Yes There are proper brackets.";nl;
    }else{
        cout<<"No There are no proper brackets.";nl;
    }
}