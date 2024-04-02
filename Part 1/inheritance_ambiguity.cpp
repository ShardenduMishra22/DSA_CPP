#include<bits/stdc++.h>
using namespace std;

#define frb(i, len) for(int i = len-1; i >= 0; i--)
#define fr(i, len) for(int i = 0; i < len; i++)
#define tas cout<<"Tell a string : ";
#define nl cout<<"\n";
#define N 1000
typedef vector<vector<string>> vvstr;
typedef vector<vector<int>> vvint;
typedef vector<string> vstr;
typedef vector<int> vint;
typedef long long int ll;
typedef const int c_int;
typedef double dbl;
int InversionCount = 0;
c_int MOD = 1e9 + 7;
c_int Mx_row = 100;
c_int Mx_col = 100;

class H1{
    public : 
    int age1;
    void func(){
        cout<<"Age is 20";
    }
};
class H2{
    public : 
    int age2;
    void func(){
        cout<<"Age is 30";
    }
};

class H3 : public H1,public H2{
    public :
    int age3;
};

int main(){
    H3 h;
    h.H1::func();
}