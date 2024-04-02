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
typedef vector<int> vint;
typedef stack<string> sstr;
typedef stack<int> sint;
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

bool knows(vvint mat, int a, int b) {
    if (mat[a][b] == 1) {
        return true;
    }
    return false;
}

int celeb(vvint& mat, int n) {
    sint s;
    fr(i, n) {
        s.push(i);   
    }
    while (s.size() > 1) {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (knows(mat, a, b)) {
            s.push(b);
        } else {
            s.push(a);
        }
    }
    int potential_celeb = s.top();
    // Verify if everybody knows the potential celebrity
    for (int i = 0; i < n; i++) {
        if (i == potential_celeb) continue;
        if (!knows(mat, i, potential_celeb)){
            return -1; // No celebrity found
        }
    }

    return potential_celeb; // Return the potential celebrity
}

// int celebrity(vvint& mat, int n) {
//     vector<int> knw_me(n, 0); 
//     vector<int> i_knw(n, 0);  
//     int i = 0, j = 0;
//     while (i < n && j < n) {
//         if (i == j) {
//             j++;
//             continue;
//         }
//         if (mat[i][j] == 1) {
//             knw_me[j]++;
//             i_knw[i]++;
//         }
//         i++; 
//         if (i == n) {
//             j++; 
//             i = 0;
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         if (knw_me[i] == n - 1 && i_knw[i] == 0) {
//             return i; 
//         }
//     }
//     return -1; 
// }

int main() {
    vvint mat = {{0, 1, 0},
                 {0, 0, 0},
                 {0, 1, 0}};
    // cout << "Potential Celebrity Index: " << celebrity(mat, 3) << endl;
    cout << celeb(mat,3);
    return 0;
}