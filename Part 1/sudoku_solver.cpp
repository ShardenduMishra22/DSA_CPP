#include<bits/stdc++.h>
using namespace std;

#define frb(i, len) for(int i = len-1; i >= 0; i--)
#define fr(i, len) for(int i = 0; i < len; i++)
#define tas cout<<"Tell a string : ";
#define all_v v.begin(), v.end()
#define YES cout<<"Yes \n";
#define No cout<<"No \n";
#define nl cout<<"\n";
#define MAX_SIZE 1000
#define pr protected
#define nptr nullptr
#define pv private
#define pb public
typedef priority_queue<long long,vector<long long>,greater<long long>> lprq_intd;
typedef priority_queue<int,vector<int>,greater<int>> prq_intd;
typedef vector<vector<string>> vvstr;
typedef priority_queue<int> prq_int;
typedef vector<vector<int>> vvint;
typedef vector<vector<bool>> vvbl;
typedef vector<string> vstr;
typedef vector<int> vint;
typedef vector<bool> vbl;
typedef long long int ll;
typedef stack<int> sint;
typedef queue<int> qint;
typedef deque<ll> dllnt;
typedef const int c_int;
typedef vector<ll> vll;
typedef double dbl;
c_int MOD = 1e9 + 7;
c_int Mx_row = 100;
c_int Mx_col = 100;
int size_stack = 0;
int InvrsnCnt = 0;
int size_arr = 0;
int size_ll = 0;
int top = -1;

bool isSafe(int row, int col, vvint& board, int val) {
    int n = board.size();

    for (int i = 0; i < n; i++) {
        if (board[row][i] == val || board[i][col] == val) {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == val) {
                return false;
            }
        }
    }
    return true;
}



bool solve(vvint& board){
    int n = board.size();
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(board[i][j] == 0){
                for(int val = 1;val <= 9;val++){
                    if(isSafe(i,j,board,val)){
                        board[i][j] = val;
                        bool next_sol = solve(board);
                        if(next_sol){
                            return true;
                        }else{
                            board[i][j] = 0;
                        } 
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){
    vvint board = {
        {5, 3, 4, 6, 7, 0, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {0, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 0},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 0, 6, 1, 7, 9}
    };

    if(solve(board)) {
        for(auto row : board) {
            for(int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }else{
        cout << "No solution exists!";
    }

    return 0;
}