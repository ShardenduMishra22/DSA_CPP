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

pair<bool,int> sum_tree(node*root){
    if(root == nptr){
        pair<bool,int>p = make_pair(true,0);
        return p;
    }
    if(root->left == nptr && root->right == nptr){
        pair<bool,int>p = make_pair(true,root->data);
        return p;
    }
    pair<bool,int> left = sum_tree(root->left);
    pair<bool,int> right = sum_tree(root->right);

    bool left_ans = left.first;
    bool right_ans = right.first;

    int left_sum = left.second;
    int right_sum = right.second;

    pair<bool,int> ans;
    if(left_ans && right_ans && root->data == left_sum + right_sum){
        ans.first = true;
        ans.second = root->data + left_sum + right_sum;
    }else{
        ans.first = false;
    }
    return ans;
}

bool isSumTree(node* root){
        return sum_tree(root).first;
}


int main(){
    node* root1 = nptr;

    BuildUsingLevelOrder(root1);
    cout << "Level Order Traversal:" << endl;
    LevelOrderTraversal(root1);
    nl;
    if(isSumTree(root1)){
        cout << "Sum of tree is constant: "<< endl;
    } else {
        cout << "Sum of tree is not constant" << endl;
    }

    return 0;
}
