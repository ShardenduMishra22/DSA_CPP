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

    pb:
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

// node*k_ancestor(node*root,vint& arr,int n1,int n2){
//     if(root == nptr){
//         return nptr;
//     }
    
//     if(root->data == n1 || root->data == n2){
//         arr.push_back(root->data);
//         return root;
//     }

//     node*left_ans = k_ancestor(root->left,arr,n1,n2);
//     node*right_ans = k_ancestor(root->right,arr,n1,n2);

//     if(left_ans == nptr && right_ans == nptr){
//         return nptr;
//     }else if(left_ans != nptr && right_ans != nptr){
//         arr.push_back(root->data);
//         return root;
//     }else if(left_ans == nptr && right_ans != nptr){
//         arr.push_back(root->data);
//         return right_ans;
//     }else if(left_ans != nptr && right_ans == nptr){
//         return left_ans;
//     }
// }

node* k_ancestor(node* root, vint& arr, int n1, int n2) {
    if (root == nullptr) {
        return nullptr;
    }
    
    // If either of the nodes is found, return that node
    if (root->data == n1 || root->data == n2) {
        arr.push_back(root->data);
        return root;
    }

    // Search for ancestors in left and right subtrees
    node* left_ans = k_ancestor(root->left, arr, n1, n2);
    node* right_ans = k_ancestor(root->right, arr, n1, n2);

    // If both nodes are found in left and right subtrees, then the current node is the lowest common ancestor
    if (left_ans != nullptr && right_ans != nullptr) {
        arr.push_back(root->data);
        return root;
    }

    // Otherwise, return the non-null subtree result
    return (left_ans != nullptr) ? left_ans : right_ans;
}

void solve(node* root, int k, int n1, int n2) {
    vint ans;
    node* temp = k_ancestor(root, ans, n1, n2);
    if (temp != nptr) {
        int j = ans.size() - k; // Compute the index of the k-th ancestor
        if (j >= 0) {
            cout << ans[j] << " is the kth ancestor!!";
        } else {
            cout << "Not there !!";
        }
    } else {
        cout << "Not there !!";
    }
    return;
}


int main() {
    node* root = nullptr;
    BuildUsingLevelOrder(root);
    
    int n1, n2, k;
    cout << "Enter the values of n1 and n2: ";
    cin >> n1 >> n2;
    cout << "Enter the value of k: ";
    cin >> k;

    solve(root, k, n1, n2);

    return 0;
}
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 