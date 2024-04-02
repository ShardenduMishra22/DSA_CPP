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
#define N 1000
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
class SpecialStack {
	stack<int> s;
    int mini = INT_MAX;
    public:
        
    void push(int data) {
        if(s.empty()) {
            s.push(data);
            mini = data;
        }else{
         	if(data < mini) {
                s.push(2*data - mini);
                mini = data;
            }else{
                s.push(data);
            }
        }
    }
    int pop() {
        if(s.empty()){
            return -1;
        }
        int curr = s.top();
        s.pop();
        if(curr > mini) {
            return curr;
        }else{
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
    }
    int top() {
        if(s.empty())
            return -1;
        int curr = s.top();
        if(curr < mini) {
            return mini;
        }
        else{
            return curr;
        }
    }
    bool isEmpty() {
        return s.empty();
    }
    int getMin() {
        if(s.empty())
            return -1;
        return mini;
    }  
};

int main() {
    SpecialStack s;
    s.push(3);
    s.push(5);
    cout << "Current top element: " << s.top() << endl;
    cout << "Minimum element: " << s.getMin() << endl;
    s.push(2);
    s.push(1);
    cout << "Current top element: " << s.top() << endl;
    cout << "Minimum element: " << s.getMin() << endl;
    cout << "Popped element: " << s.pop() << endl;
    cout << "Minimum element: " << s.getMin() << endl;
    cout << "Popped element: " << s.pop() << endl;
    cout << "Current top element: " << s.top() << endl;
    cout << "Minimum element: " << s.getMin() << endl;
    return 0;
}
