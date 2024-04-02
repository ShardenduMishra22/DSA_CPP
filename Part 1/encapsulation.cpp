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

class Car {
private:
    string brand;    // Encapsulated attribute
    int year;        // Encapsulated attribute

public:
    // Public member functions to set and get the encapsulated attributes
    void setBrand(string b) {
        brand = b;
    }
    string getBrand() {
        return brand;
    }
    void setYear(int y) {
        year = y;
    }
    int getYear() {
        return year;
    }
};

int main() {
    // Create an object of the Car class
    Car myCar;
    // Set the attributes using public member functions
    myCar.setBrand("Toyota");
    myCar.setYear(2020);
    // Access and display the attributes using public member functions
    cout << "Car Brand : " << myCar.getBrand() << endl;
    cout << "Car Year  : " << myCar.getYear()  << endl;
    return 0;
}