#include <bits/stdc++.h>
using namespace std;

#define frb(i, len) for (int i = len - 1; i >= 0; i--)
#define fr(i, len) for (int i = 0; i < len; i++)
#define tas cout << "Tell a string : ";
#define YES cout << "Yes \n";
#define No cout << "No \n";
#define nl cout << "\n";
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

node* buildTree(node* root){
    cout<<"Tell the data : ";
    int data;cin>>data;
    root = new node(data);
    if(data == -1) return nptr;

    cout<<"Tell the data at the left of "<<data ;nl;
    root->left = buildTree(root->left);

    cout<<"Tell the data at the right of "<<data ;nl;
    root->right = buildTree(root->right);

    return root;
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
void printGivenLevel(node* root, int level){ 
    if (root == NULL) 
        return; 
    if (level == 1) 
        cout << root->data << " "; 
    else if (level > 1) { 
        printGivenLevel(root->left, level - 1); 
        printGivenLevel(root->right, level - 1); 
    } 
}
int height(node* node) { 
    if (node == NULL) 
        return 0; 
    else{ 
        int left = height(node->left); 
        int right = height(node->right); 

        int ans = max(left, right) + 1;
        return ans; 
    } 
}

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
            temp->left = nullptr; // No left child
        }
        
        cout<<"Tell the right data (-1 for no node) : ";
        int r;cin>>r;
        if(r != -1){
            temp->right = new node(r);
            q.push(temp->right);
        }
        else {
            temp->right = nullptr; // No right child
        }
    }    
}

int diameter(node*root){
    if(root == nptr){
        return 0;
    }
    int opr1 = diameter(root->left);
    int opr2 = diameter(root->right);
    int opr3 = height(root->right) + height(root->left) + 1;

    int ans = max(opr1,max(opr2,opr3));
    return ans ;
}

pair<int,int> fast_diameter(node*root){
    if(root == nptr){
        pair<int,int>p = make_pair(0,0);
        return p;
    }
 
    pair<int,int> left = fast_diameter(root->left);
    pair<int,int> right = fast_diameter(root->right);
 
    int opr1 = left.first;
    int opr2 = right.first;
    int opr3 = left.second + right.second + 1;
 
    pair<int,int>ans;
    ans.first = max(opr1,max(opr2,opr3));
    ans.second = max(left.second , right.second) + 1;

    return ans; 
}

int dia(node*root){
    return fast_diameter(root).first;
}

int main(){
    node*root = nptr;
    BuildUsingLevelOrder(root);
    //   cout<<"The diameter is : "<< diameter(root);
    cout<<"The diameter is : "<< dia(root);
    // 1 2 3 4 5 6 -1 -1 -1 -1 -1 -1 -1 -1
}