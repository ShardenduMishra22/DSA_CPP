#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
static auto _ = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define frb(i, len) for(int i = len-1; i >= 0; i--)
#define fr(i, len) for(int i = 0; i < len; i++)

#define rvrs(a) reverse(a.begin(),a.end())
#define srt(a) sort(a.begin(),a.end())

#define YES cout<<"Yes \n";
#define NOO cout<<"No  \n";
#define nl cout<<"\n";

#define MAX_SIZE 10000
#define nptr nullptr

typedef stringstream strgm;
typedef long long int ll;
typedef const int c_int;
typedef unsigned unsg;
typedef double dbl;

typedef vector<vector<string>> vvstr;
typedef vector<vector<bool>> vvbl;
typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvll;

typedef vector<string> vstr;
typedef vector<int> vint;
typedef vector<bool> vbl;
typedef vector<ll> vll;

typedef stack<string> sstr;
typedef stack<bool> sbl;
typedef stack<int> sint;
typedef stack<ll> sll;

typedef queue<string> qstr;
typedef queue<bool> qbl;
typedef queue<int> qint;
typedef queue<ll> qll;

c_int MOD = 1e9 + 7;
c_int Mx_row = 100;
c_int Mx_col = 100;
int size_stack = 0;
int InvrsnCnt = 0;
int size_arr = 0;
int size_ll = 0;
int top = -1;

int Partition(vint& arr,int l,int r){
    int pvt = arr[r];
    int i = l - 1;
    for(int j = l;j < r;j++){
        if(arr[j] < pvt){
            i++;
            swap(arr[i],arr[j]); 
        }
    }
    swap(arr[i + 1],arr[r]);
    return i + 1;
}

void Quick(vint& arr,int l,int r){
    if(l < r){
        int prtn = Partition(arr,l,r);
        Quick(arr,l,prtn-1);
        Quick(arr,prtn+1,r);
    }
}

void mergeSort(vint& arr,int l,int m,int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    vint arr1(n1,0);
    vint arr2(n2,0);

    for(int i=0;i<n1;i++){
        arr1[i] = arr[l + i];
    }

    for(int i=0;i<n2;i++){
        arr2[i] = arr[m + i + 1];
    }

    int  i=0,j=0,k=l;
    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]) arr[k++] = arr1[i++];
        else arr[k++] = arr2[j++];
    }
    while(i<n1){
        arr[k++] = arr1[i++];
    }
    while(j<n2){
        arr[k++] = arr2[j++];
    }
}

void Merge(vint& arr,int l,int r){
    if(l < r){
        int mid = l + (r - l)/2;
        Merge(arr,l,mid);
        Merge(arr,mid+1,r);
        mergeSort(arr,l,mid,r);
    }
}

int main(){
    vint arr = {1,5,3,6,8,3,9,0,3,6};
    Merge(arr,0,arr.size()-1);
    for(int i : arr){
        cout<<i<<" ";
    }
    // nl;
    // Quick(arr,0,arr.size()-1);   
    // for(int i : arr){
    //     cout<<i<<" ";
    // }
    nl;
}