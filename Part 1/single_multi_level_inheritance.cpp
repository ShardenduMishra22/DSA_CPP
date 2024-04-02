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

// This is Single Level inheritance
class Animal {
    public :
    int age;
    void spk(){
        cout<<"Hi Bro";
    }
};
class Dog : public Animal{
    public:
    string breed;
};
// This is multilevel inheritance 
class Puppy: public Dog{
    public:
    string color;
};
int main(){
    Dog d1;
    d1.age = 15;
    d1.breed = "GSD";
    cout<<"Age is : "<<d1.age<<", and the breed is : "<<d1.breed; nl;

    Puppy p1;
    p1.age = 1;
    p1.breed = "GSD";
    p1.color = "Brwon";
    cout<<"Age is : "<<p1.age<<", and the breed is : "<<p1.breed<<" and the color is : "<<p1.color; nl;


}