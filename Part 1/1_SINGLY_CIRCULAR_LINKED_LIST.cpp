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
typedef long long int ll;
typedef const int c_int;
typedef double dbl;
int InversionCount = 0;
int size_ll = 0;
c_int MOD = 1e9 + 7;
c_int Mx_row = 100;
c_int Mx_col = 100;

class node{
    pb:
    int data;
    node* next;
    node(int data){
        this->data = data;
        this->next = nptr;
    }
};

class LinkedList{
    pb:
    node* head;
    node* tail;
    LinkedList(){
        head = nptr;
        tail = nptr;
        size_ll = 0;
    }
    ~LinkedList(){
        node*temp=head,*frwd;
        while(temp != nptr){
            frwd = temp->next;
            delete temp;
            temp = frwd;
        }
    }
};