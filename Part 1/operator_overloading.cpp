#include <bits/stdc++.h>
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

class Number {
public:
    int a;
    int b;

    // Overloaded operator+
    int operator+ (Number& num1) {
        int v1 = this->a;
        int v2 = num1.a;
        return v2 - v1; // Corrected the subtraction operation
    }
}; // Added a semicolon here

int main() { 
    Number n1, n2;
    n1.a = 10;
    n2.a = 15; // Corrected the assignment of values
    int result = n1 + n2; // Assigned the result to a variable
    cout << "Result: " << result << endl; // Printing the result
    return 0;
}
