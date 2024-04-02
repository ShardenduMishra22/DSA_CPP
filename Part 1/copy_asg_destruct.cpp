#include<bits/stdc++.h>
using namespace std;

#define frb(i, len) for(int i = len-1; i >= 0; i--)
#define fr(i, len) for(int i = 0; i < len; i++)
#define tas cout<<"Tell a string : ";
#define nl cout<<"\n";
#define N 1000
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

class Hero{
    private :
    int level;

    public:
    string name;
    Hero(string name,int level){
        this->level = level;
        this->name = name;
    }

    void print(){
        cout<<"The data of the person is given by : \n";
        cout<<"Name is : "<<this->name  ; nl;
        cout<<"The Level is : "<<this->level ; nl;
    }
};

int main(){
    Hero h1("Shardendu Mishra",10);
    h1.print();nl;

    Hero h2("Shardendu Mishra 2",15);
    h2.print();nl;

    h1.print();nl;
    h2.print();nl;

    h2 = h1;

    h1.print();nl;
    h2.print();nl;

    h1.name[0] = '&';

    h1.print();nl;
    h2.print();nl;
}