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

node* lca(node*root,int n1,int n2){
    if(root == nptr) return nptr;
    if(root->data == n1 || root->data == n2) return root;
    node*left_ans = lca(root->left,n1,n2);
    node*right_ans = lca(root->right,n1,n2);

    if(left_ans != nptr && right_ans != nptr){
        return root;
    }else if(left_ans == nptr && right_ans == nptr){
        return nptr;
    }else if(left_ans == nptr && right_ans != nptr){
        return right_ans;
    }else if(left_ans != nptr && right_ans == nptr){
        return left_ans;
    }
}

int main() {
    node* root = nullptr;
    BuildUsingLevelOrder(root);
    cout << "Level Order Traversal:" << endl;
    LevelOrderTraversal(root);
    nl;
    int n1, n2;
    cout << "Enter two nodes to find their Lowest Common Ancestor: ";
    cin >> n1 >> n2;
    node* ancestor = lca(root, n1, n2);
    if (ancestor != nullptr) {
        cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is: " << ancestor->data << endl;
    } else {
        cout << "No Lowest Common Ancestor found for nodes " << n1 << " and " << n2 << endl;
    }

    return 0;
}
