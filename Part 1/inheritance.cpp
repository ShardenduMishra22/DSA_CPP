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

class Student{
    private : 
    int age;
        float marks;
        string name;

    public:
        int set_age(int age){
            this->age = age;
        }
        float set_marks(float marks){
            this->marks = marks;
        }
        string set_name(string name){
            this->name = name;
        }

        // Student(string name,int age, float marks) {
        //     this->age = age;
        //     this->marks = marks;
        //     this->name = name;
        // }

        void get_age(){
            cout<<"The age is : "<<this->age;nl;
        }
        void get_marks(){
            cout<<"The Marks are : "<<this->marks;nl;
        }
        void get_string(){
            cout<<"The Name is : "<<this->name;nl;
        }

        // void prnt() {
        //     cout << "Name:  " << name  << endl;
        //     cout << "Age:   " << age   << endl;
        //     cout << "Marks: " << marks << endl;
        // }
};

class Male : public Student{
    public :
        string color;

        void slp(){
            cout<<"Sleeping \n";
        }
};

int main(){
    Male s1;
    s1.color = "Red";
    s1.set_age(20);
    s1.set_marks(98.76);
    s1.set_name("Shardendu Mishra");
    
        
}