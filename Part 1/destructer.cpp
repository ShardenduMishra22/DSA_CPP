#include<bits/stdc++.h>
using namespace std;

#define frb(i, len) for(int i = len-1; i >= 0; i--)
#define fr(i, len) for(int i = 0; i < len; i++)
#define tas cout<<"Tell a string  : ";
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

// class Student{
//     char a;
//     char b;
//     int data;
// };

// class Hero{
//     public :
//     int level;
//     float marks;
//     string name;    
// };

// class Example {
//     private:
//         int x;
//         string message;

//     public:
//         Example (int x_val, string msg = "Custom message") {
//             x = x_val;
//             message = msg;
//         }
//         int getX() {
//             return x;
//         }
//         string getMessage() {
//             return message;
//         }
// };

class Hero{
    private :
    string name;
    float health;
    int level;
    char grade; 

    public :
    // Default constructor
    Hero() {
        cout << "Default Constructor called. \n";
        name = ""; // Initialize name to an empty string
        health = 0.0; // Initialize health to 0
        level = 0; // Initialize level to 0
        grade = ' '; // Initialize grade to a space character
    }

    // Parameterised constructor
    Hero(string name,float health,int level,char grade){
        this->name = name;
        this->health = health;
        this->level = level;
        this->grade = grade;
    }

    void print() {
        cout << "Name: "  << this->name   << "\n";
        cout << "Level: " << this->level  << "\n";
        cout << "Health: "<< this->health << "\n";
        cout << "Grade: " << this->grade  << "\n";
    }

    // Hero (Hero& temp){
    //     this->name   = temp.name  ;
    //     this->health = temp.health;
    //     this->level  = temp.level ;
    //     this->grade  = temp.grade ;
    // }

    // void set_Name(string ch){
    //     name = ch;
    // }
    // void set_Health(float h){
    //     health = h;       
    // }
    // void set_Grade(char n) {
    //     if (level <= 10) {
    //         cout << "Get a better grade \n";
    //         return;
    //     }
    //     grade = n;
    // }
    // void set_Level(int l){
    //     level = l;
    // }
    // int get_level(){
    //     return level;
    // }
    // float get_health(){
    //     return health;
    // }
    // char get_grade(){
    //     return grade;
    // }
    // string get_name(){
    //     return name;
    // }
    // protected :

    ~Hero(){
        cout<<"Destroyed \n";
    }
};

int main(){
    // static thus auto call destructor 
    Hero P("Shardendu1 Mishra1",92.7,90,'B');
    P.print();
    
    nl;nl;
    
    // dynamic we have to call destructor  
    Hero*R = new Hero("Shardendu Mishra",92.87,98,'A');
    R->print();

    nl;nl;

    delete R;

    // Hero S(R);
    // S.print();

    // Hero*Ramesh2 = new Hero("Shardendu Mishra",92.87,98,'A');
    // cout<<Ramesh2->get_name()<<"\n";
    // cout<<Ramesh2->get_level()<<"\n";
    // cout<<Ramesh2->get_health()<<"\n";
    // cout<<Ramesh2->get_grade()<<"\n";

    // Hero Ramesh("Shardendu Mishra",92.87,98,'A');
    // cout<<Ramesh.get_name()<<"\n";
    // cout<<Ramesh.get_level()<<"\n";
    // cout<<Ramesh.get_health()<<"\n";
    // cout<<Ramesh.get_grade()<<"\n";

    // Hero();

    // Example obj2(10, "Hello");
    // cout << "Object 2 created using parameterized constructor: ";
    // cout << "x: " << obj2.getX() << ", Message: " << obj2.getMessage() << endl;

    // Example obj3(20);
    // cout << "Object 3 created using parameterized constructor with default parameter: ";
    // cout << "x: " << obj3.getX() << ", Message: " << obj3.getMessage() << endl;

    // cout<<"You have reached here 1.) \n";
    // Hero Raju;
    // cout<<"Ended. 3.) \n";

    // cout<<"You have reached here again 1.) \n";
    // Hero*Kaju = new Hero; /* new Hero() */
    // cout<<"Ended again. 3.) \n";

    // Hero*a = new Hero;
    // (*a).level = 10; 
    // a->marks = 99.54;
    // a->name =  "Shardendu Mishra";

    // cout<<"Name is : "<<a->name<<"\n";
    // cout<<"Level is : "<<a->level<<"\n";
    // cout<<"Marks recivied : "<<a->marks<<"\n";

    // cout<<sizeof(Student);

    // Hero h1;
    // h1.name = "Shardendu Mishra";
    // h1.health = 99.76;
    // h1.grade = 'A';
    // h1.level = 12;
    // cout<<h1.health<<" "<<h1.name<<" "<<h1.level<<" "<<h1.grade;

    // Hero h2;
    // h2.set_Name("Aragorn");
    // h2.set_Health(95.5);
    // h2.set_Level(20);
    // h2.set_Grade('A');

    // // Retrieving values using getter methods
    // cout << "Name : " << h2.get_name() << endl;
    // cout << "Health : " << h2.get_health() << endl;
    // cout << "Level : " << h2.get_level() << endl;
    // cout << "Grade : " << h2.get_grade() << endl;

    // Hero h3;
    // h3.set_Name("Krishna");
    // h3.set_Health(98.5);
    // h3.set_Grade('D');
    // h3.set_Level(4);

    // // Retrieving values using getter methods
    // cout << "Name : " << h3.get_name() << endl;
    // cout << "Health : " << h3.get_health() << endl;
    // cout << "Level : " << h3.get_level() << endl;
    // cout << "Grade : " << h3.get_grade() << endl;

}