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

vint nextSmallest(vint& arr) {
    stack<int> s;
    int n = arr.size();
    vint next(n);
    s.push(-1);
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[i] <= arr[s.top()]) {
            s.pop();
        }
        if (s.empty()) {
            next[i] = n;
        } else {
            next[i] = s.top();
        }
        s.push(i);
    }
    return next;
}

vint prevSmallest(vint& arr) {
    stack<int> s;
    int n = arr.size();
    vint prev(n);
    s.push(-1);
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[i] <= arr[s.top()]) {
            s.pop();
        }
        if (s.empty()) {
            prev[i] = -1;
        } else {
            prev[i] = s.top();
        }
        s.push(i);
    }
    return prev;
}

int largestRectangleArea(vint& heights) {
    int n = heights.size();
    vint next = nextSmallest(heights);
    vint prev = prevSmallest(heights);
    int area = -1;
    for (int i = 0; i < n; i++) {
        int l = heights[i];
        int b = next[i] - prev[i] - 1;
        int m = l * b;
        area = max(area, m);
    }
    return area;
}

int maxArea(vvint& matrix) {
    int n = matrix.size(); // row
    if (n == 0) return 0;
    int m = matrix[0].size(); // column
    if (m == 0) return 0;
    vint heights(m, 0);
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                heights[j] = 0;
            } else {
                heights[j] += matrix[i][j];
            }
        }
        maxArea = max(maxArea, largestRectangleArea(heights));
    }
    return maxArea;
}

int main() {
    vvint matrix = {{0, 1, 1, 0},
                  {1, 1, 1, 1},
                  {1, 1, 1, 1},
                  {1, 1, 0, 0}};
    cout << "Maximum Area of Rectangles: " << maxArea(matrix) << endl;
    return 0;
}
