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
int size_ll = 0;
int size_arr = 0;
int top_st = -1;
c_int MOD = 1e9 + 7;
c_int Mx_row = 100;
c_int Mx_col = 100;

int main(){
    stack<int>st ;
    string str = "MalayalaM";
    fr(i,str.length()) st.push(str[i]);

    string ans = "";
    fr(i,str.length()) {
        ans.push_back(st.top());
        st.pop();
    }
    cout<<"The reveresd string is : "<<ans;
    nl;
    bool isPalindrome = true;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ans[i]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        cout << "It's a Palindrome" << endl;
    } else {
        cout << "Not a Palindrome" << endl;
    }

    return 0;
}