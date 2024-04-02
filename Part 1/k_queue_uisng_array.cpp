#include<bits/stdc++.h>
using namespace std;

#define frb(i, len) for(int i = len-1; i >= 0; i--)
#define fr(i, len) for(int i = 0; i < len; i++)
#define tas cout<<"Tell a string : ";
#define nl cout<<"\n";
#define MAX_SIZE 1000
#define pr protected
#define nptr nullptr
#define pv private
#define pb public
typedef vector<vector<string>> vvstr;
typedef vector<vector<int>> vvint;
typedef vector<string> vstr;
typedef vector<int> vint;
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

class kQueue{
    pb:
    int *front;
    int *arr;
    int *rear;
    int *next;
    int freespot;
    int n;
    int k;

    kQueue(int n,int k){
        this->n = n;
        this->k = k;
        front = new int[k];
        rear = new int[k];
        fr(i,k){
            front[i] = -1;
            rear[i]  = -1;
        }
        next = new int[n];
        fr(i,n){
            next[i] = i+1;
            if(i == n-1){
                next[i] = -1;
            }
        }
        arr = new int[n];
        freespot = 0;
    }
    void enqueue(int data,int queue_number){
        if(freespot == -1){
            cout<<"Full !!";
            return;
        }
        int index = freespot;
        freespot = next[index];
        if (front[queue_number - 1] == -1){
            front[queue_number - 1] = index;
        }else{
            next[rear[queue_number - 1]] = index;
        }
        next[index] = -1;
    }
    void dequeue(int queue_number){
        if(front[queue_number - 1]== -1){
            cout<<"Empty";
            return;
        }
        int index = front[queue_number - 1];
        front[queue_number - 1] = next[index];
        next[index] = freespot;
        freespot = index;
    }
};
int main() {
    int n = 10; 
    int k = 3;  
    kQueue q(n, k);
    q.enqueue(10, 1);
    q.enqueue(20, 2);
    q.enqueue(30, 3);
    q.enqueue(40, 1);
    q.enqueue(50, 2);
    q.dequeue(1);    
    q.dequeue(2);    
    q.dequeue(3);    
    return 0;
}
