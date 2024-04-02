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

class Solution {
private:
    
    
    // arr is the array that is used to store the value of actual array.
    vector<int> nextSmallerElement(vint arr, int n) {
        stack<int>s ;
        s.push(-1);
        vint ans(n);
        for(int i = n - 1;i >= 0;i--){
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(vint arr, int n) {
        stack<int>s ;
        s.push(-1);
        vint ans(n);
        for(int i = 0;i < n;i--){
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n =  heights.size();
        vint next(n),prev(n);
        next = nextSmallerElement(heights,n);
        prev = prevSmallerElement(heights,n);

        int area = -1;
        fr(i,n){
            int l = heights[i];
            if (next[i] == -1){
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newArray = l * b;
            area = max(area,newArray);
        }
        return area;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {6, 2, 5, 4, 5, 1, 6};
    int result = sol.largestRectangleArea(heights);
    cout << "Largest Rectangle Area: " << result << endl;
    return 0;
}
