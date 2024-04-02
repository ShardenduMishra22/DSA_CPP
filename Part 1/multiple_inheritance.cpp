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

class Male {
    public:
    int age;
    string name;
};

class Female {
    public:
    int level;
    string last_name;
};

class Human : public Male, public Female {
    public:
    float marks;
};

int main() {
    Human h1;
    
    h1.age   = 10;
    h1.level = 92;
    h1.marks = 98.43; 
    
    cout << "Age: " << h1.age << endl;
    cout << "Level: " << h1.level << endl;
    cout << "Marks: " << h1.marks << endl;
    
    return 0; 
}