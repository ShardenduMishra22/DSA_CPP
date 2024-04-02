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
private:

public:
    int health;
    char *name;
    char level;
    
    // Default constructor
    Hero() {
        name = new char[1]; 
        name[0] = '\0';     
        health = 0;         
        level = ' ';        
    }
    
    // Copy constructor
    Hero(Hero& temp) {
        cout << "Copy constructor called" << endl;
        
        // Allocate memory for name and copy contents
        name = new char[strlen(temp.name) + 1];
        strcpy(name, temp.name);
        
        // Copy other member variables
        health = temp.health;
        level = temp.level;
    }


    void print(){
        cout << endl;
        cout << "Name   : " << this->name   << "\n";
        cout << "Health : " << this->health << "\n";
        cout << "level  : " << this->level  << "\n";
        cout << endl << endl;
    }
};

int main(){
    Hero h1;
    strcpy(h1.name , "Babbar"); // Set name
    h1.print();
   
    // use default copy constructor
    Hero h2(h1);
    h2.print();

    h1.name[0] = 'G'; // Modify name in h1

    h1.print(); // Print h1
    h2.print(); // Print h2 (should not be affected by changes to h1)

    return 0;   
}