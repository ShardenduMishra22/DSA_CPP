#include <bits/stdc++.h>
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
#define N 4

typedef vector<vector<int>> vvint;

void printSolution(vvint& board)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            if(board[i][j])
                cout << "\tQ";
            else
                cout<<"\t_";
        printf("\n");
    }
}

bool isSafe(vvint& board, int row, int col){
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(vvint& board, int col)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if(isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveNQUtil(board, col + 1))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

bool solveNQ()
{
    vvint board(N, vector<int>(N, 0));
    if (solveNQUtil(board, 0) == false) {
        cout << "Solution does not exist";
        return false;
    }

    printSolution(board);
    return true;
}

int main()
{
    solveNQ();
    return 0;
}
