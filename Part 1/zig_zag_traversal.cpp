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

// Define the node structure for the binary tree
class node{
public:
    node* right;
    node* left;
    int data;

    // Constructor to initialize a node
    node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Function to build the binary tree using level order traversal
void BuildUsingLevelOrder(node*& root){
    queue<node*> q;
    cout << "Enter the root data: ";
    int d; cin >> d;
    root = new node(d);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        cout << "Enter the left child data of " << temp->data << " (-1 for no node): ";
        int l; cin >> l;
        if(l != -1){
            temp->left = new node(l);
            q.push(temp->left);
        }
        
        cout << "Enter the right child data of " << temp->data << " (-1 for no node): ";
        int r; cin >> r;
        if(r != -1){
            temp->right = new node(r);
            q.push(temp->right);
        }
    }    
}

// Function to perform level order traversal of the binary tree
void LevelOrderTraversal(node* root){
    if(root == nullptr) return;
    queue<node*> q;
    q.push(root);
    q.push(nullptr); // Use nullptr as a level delimiter

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == nullptr){
            nl;
            if(!q.empty()){
                q.push(nullptr);
            }
        } else {
            cout << temp->data << " ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    } 
    nl;
}

vint zig_zag_traversal(node*root){
    vint res;
    if(root == nptr) return res;
    queue<node*>q;
    q.push(root);

    bool isDirn = true;
    while(!q.empty()){
        // jis level pe uska size
        int size = q.size();
        vint ans(size);
        for(int i = 0;i<size;i++){
            node*temp = q.front();
            q.pop();

            // which index to add the element
            int index = isDirn ? i : size - i - 1;
            ans[index] = temp->data;

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        isDirn = !isDirn;
        for(auto i : ans){
            res.push_back(i);
        }
    }
    return res;
}

int main() {
    node* root = nullptr;
    BuildUsingLevelOrder(root); // Build the binary tree using level order traversal
    nl;
    vint arr = zig_zag_traversal(root);
    fr(i,arr.size()){
        cout<<arr[i]<<" ";
    }
    // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
    return 0;
}
