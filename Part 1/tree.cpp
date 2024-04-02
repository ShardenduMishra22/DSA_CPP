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
        int lheight = height(node->left); 
        int rheight = height(node->right); 

        if (lheight > rheight) 
            return(lheight + 1); 
        else return(rheight + 1); 
    } 
}
void reverseLevelOrder(node* root) { 
    int h = height(root); 
    int i; 
    for (i=h; i>=1; i--){  
        printGivenLevel(root, i);
        nl;
    } 
}

void in_order(node* root){
    if(root == nptr){
        return;
    }
    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);
}

void pre_order(node* root){
    if(root == nptr){
        return;
    }
    cout<<root->data<<" ";
    pre_order(root->left);
    pre_order(root->right);
}

void post_order(node* root){
    if(root == nptr){
        return;
    }
    post_order(root->left);
    post_order(root->right);
    cout<<root->data<<" ";
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

void CntLeafNode(node*& root,int& cnt){
    if(root == nptr){
        return;
    }
    node*temp = root;
    if(temp->left == nptr) cnt += 1;
    if(temp->right == nptr) cnt += 1;
    CntLeafNode(temp->left,cnt);
    CntLeafNode(temp->right,cnt);   
}

int main(){
    node*root = nptr;
    int cnt = 0;
    BuildUsingLevelOrder(root);
    CntLeafNode(root,cnt);
    cout<<"The number of nodes is : "<<cnt;

    // root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // nl;
    // LevelOrderTraversal(root);
    // reverseLevelOrder(root);
    // nl;
    // cout<<"In order traversal : ";
    // in_order(root);
    // nl;
    // cout<<"Pre order traversal : ";
    // pre_order(root);
    // nl;
    // cout<<"Post order traversal : ";
    // post_order(root);
    // BuildUsingLevelOrder(root);
    // 1 2 3 4 5 -1 -1 - 1 -1 6 -1
    // LevelOrderTraversal(root);

}