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

void chck(string& str){
    if(str.length()&1){
        cout << "It's not possible to balance the braces.\n";
        return;
    }
    
    stack<char> s;
    int openBraces = 0, closedBraces = 0;
    
    for(char ch : str){
        if(ch == '{'){
            s.push(ch);
            openBraces++;
        } else if(ch == '}') {
            if(!s.empty() && s.top() == '{'){
                s.pop();
                openBraces--;
            } else {
                closedBraces++;
            }
        }
    }
    
    if(openBraces == 0 && closedBraces == 0){
        cout << "The minimum cost is: 0\n";
    } else {
        int minCost = (openBraces + 1) / 2 + (closedBraces + 1) / 2;
        cout << "The minimum cost is: " << minCost << "\n";
    }
}

int main(){
    string str1 = "}}}}}}{{{{{{";
    string str2 = "}}}}";
    string str3 = "{{{{{";

    chck(str1);
    chck(str2);
    chck(str3);
}