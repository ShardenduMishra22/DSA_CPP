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

class node{
    pb:
    node*right;
    node*left;
    int data;


    node(int data){
        this->data = data;
        this->left = nptr;
        this->right= nptr;
    }
};

// node* buildTree(node* root){
//     cout<<"Tell the data : ";
//     int data;cin>>data;
//     root = new node(data);
//     if(data == -1) return nptr;

//     cout<<"Tell the data at the left of "<<data ;nl;
//     root->left = buildTree(root->left);

//     cout<<"Tell the data at the right of "<<data ;nl;
//     root->right = buildTree(root->right);

//     return root;
// }

void BuildUsingLevelOrder(node*& root){
    queue<node*> q;
    cout<<"Tell the data : ";
    int d;cin>>d;
    root = new node(d);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        cout<<"Tell the left data (-1 for no node) : ";
        int l;cin>>l;
        if(l != -1){
            temp->left = new node(l);
            q.push(temp->left);
        }
        else {
            temp->left = nptr; 
        }
        
        cout<<"Tell the right data (-1 for no node) : ";
        int r;cin>>r;
        if(r != -1){
            temp->right = new node(r);
            q.push(temp->right);
        }
        else {
            temp->right = nptr;
        }
    }    
}

void LevelOrderTraversal(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node*temp = q.front();
        q.pop();

        if(temp == nptr){
            nl;
            if(!q.empty()){
                q.push(nptr);
            }
        }else{
            cout<<" "<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    } 
}

// height , sum
pair<int,int> Lngst_bldln_sum(node*root){
    if(root == nptr){
        pair<int,int>ans = make_pair(0,0);
        return ans;
    }
    pair<int,int> l = Lngst_bldln_sum(root->left);
    pair<int,int> r = Lngst_bldln_sum(root->right);
    
    int l_hght = 1 + l.first;
    int r_hght = 1 + r.first;

    int l_sum = root->data + l.second;
    int r_sum = root->data + r.second;
    

    pair<int,int>ans;
    if(l_hght > r_hght){
        ans = make_pair(l_hght,l_sum);
    }else{
        ans = make_pair(r_hght,r_sum);
    }
    return ans;
}

int main() {
    node* root = nullptr;
    BuildUsingLevelOrder(root);
    cout << "Level Order Traversal:" << endl;
    LevelOrderTraversal(root);
    nl;
    pair<int, int> result = Lngst_bldln_sum(root);
    cout << "Longest BloodLine Sum: " << result.first << endl;
    cout << "Sum of Nodes: " << result.second << endl;

    return 0;
}
// 4 2 5 7 1 2 3 -1 -1 6 -1 -1 -1 -1 -1 -1 -1 