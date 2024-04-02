#include<bits/stdc++.h>
using namespace std;

#define frb(i, len) for(int i = len-1; i >= 0; i--)
#define fr(i, len) for(int i = 0; i < len; i++)
#define tas cout<<"Tell a string : ";
#define YES cout<<"Yes \n";
#define No cout<<"No \n";
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

void mke_arr(int arr[],int len){
    cout<<"Tell all the elements : ";
    for(int i=0;i<len;i++){
        cin>>arr[i];
    }
}
void prnt_arr(int arr[],int len){
    cout<<"The elements of the array are : ";
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
}
void mke_vec(vector<int>&vec,int len) {
    cout << "Tell all the elements : ";
    vec.resize(len);
    for (int i = 0; i < len; i++) {
        cin >>vec[i];
    }
}
void prnt_vec(vector<int>&vec) {
    cout << "The elements of the vector are : ";
    int len = vec.size();
    for (int i = 0;i<len;i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}
void swp(int& a, int& b) {
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
}
int main(){
    // int len;
    // cout<<"Tell the length : ";
    // cin>>len;
    // int arr[len];
    // mke_arr(arr,len);
    // prnt_arr(arr,len);
    
        // nl;
    // vector<int>v(len,0);
    // mke_vec(v,len);
    // prnt_vec(v);
    // nl;
    int a = 10;
    int b = 2;
    swp(a,b);
    cout<<a<<" "<<b;
}