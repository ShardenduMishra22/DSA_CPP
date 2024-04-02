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
#define MAX_SIZE 1000
typedef vector<vector<string>> vvstr;
typedef vector<vector<int>> vvint;
typedef vector<string> vstr;
typedef stack<int> vstk;
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


class NStack {
    int* arr;
    int* top;
    int* next;
    int n, s, freespot;
    
public:
    NStack(int N, int S){
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n]; 
        next = new int[s];
        for(int i=0; i<n; i++) {
            top[i] = -1;
        }
        for(int i=0; i<s; i++) {
            next[i] = i+1;
        }
        next[s-1] = -1;
        freespot = 0;      
    }
    void push(int x, int m){ // m is which stack to add in 
        if (freespot == -1){
            cout<<"It's full";
            return ;
        }
        int index = freespot;
        freespot = next[index];
        arr[index] = x;
        next[index] = top[m-1];
        top[m-1] = index;    
        return ;
        // m is the stack in which we hav to add elemnet eg s1 ,s2 s3  
    }
    int pop(int m) {
        if (top[m - 1] == -1) {
            cout << "Already empty !!" << endl;
            return -1; // Return a default value to indicate error
        }
        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};

int main() {
    NStack nStack(3, 10);
    nStack.push(5, 3); 
    nStack.push(10, 2); 
    nStack.push(15, 1); 
    cout << "Popped from stack 1: " << nStack.pop(1) << endl;
    cout << "Popped from stack 2: " << nStack.pop(2) << endl;
    cout << "Popped from stack 3: " << nStack.pop(3) << endl;
    return 0;
}
