#include <bits/stdc++.h>
using namespace std;

#define frb(i, len) for(int i = len-1; i >= 0; i--)
#define fr(i, len) for(int i = 0; i < len; i++)
#define tas cout<<"Tell a string : ";
#define all_v v.begin(), v.end()
#define YES cout<<"Yes \n";
#define No cout<<"No \n";
#define nl cout<<"\n";
#define MAX_SIZE 1000
#define pr protected
#define nptr nullptr
#define pv private
#define pb public
typedef priority_queue<long long,vector<long long>,greater<long long>> lprq_intd;
typedef priority_queue<int,vector<int>,greater<int>> prq_intd;
typedef vector<vector<string>> vvstr;
typedef priority_queue<int> prq_int;
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

class TrieNode {
    public:
    char data;
    TrieNode* children[26];
    int ChildNodes;
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        ChildNodes = 0;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    bool SearchUtil(TrieNode* root, string word) {
        if(word.length() == 0) {
            return root->isTerminal;
        }
        int idx = word[0] - 'a';
        TrieNode* child;

        if(root->children[idx] != NULL) {
            child = root->children[idx];
        } else {
            return false;
        }
        return SearchUtil(child, word.substr(1));
    }

    bool Search(string word) {
        return SearchUtil(root, word);
    }

    void insertUtil(TrieNode* root, string word) {
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }
        int idx = word[0] - 'a';
        TrieNode* child;

        if(root->children[idx] != NULL) {
            child = root->children[idx];
        } else {
            child = new TrieNode(word[0]);
            root->ChildNodes += 1;
            root->children[idx] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void Insert(string word) {
        insertUtil(root, word);
    }

    TrieNode* remove(TrieNode* root, string word) {
        if (root == NULL) {
            return NULL;
        }

        if (word.empty()) {
            if (root->isTerminal) {
                root->isTerminal = false;
            }

            if (isEmpty(root)){
                delete root;
                root = NULL;
            }

            return root;
        }

        int index = word[0] - 'a';
        root->children[index] = remove(root->children[index], word.substr(1));

        if (isEmpty(root) && !root->isTerminal) {
            delete root;
            root = NULL;
        }

        return root;
    }

    bool isEmpty(TrieNode* root) {
        for (int i = 0; i < 26; i++) {
            if (root->children[i] != NULL) {
                return false;
            }
        }
        return true;
    }

    void lcpUtil(TrieNode* root, string& ans){
        if(root->ChildNodes > 1 || root->isTerminal) {
            return;
        }
        for(int i = 0; i < 26; i++) {
            if(root->children[i] != NULL) {
                ans.push_back('a' + i);
                lcpUtil(root->children[i], ans);
                break;
            }
        }
    }

    string LongestCommonPrefix(vector<string>& arr, int n){
        for(int i = 0; i < n; i++){
            Insert(arr[i]);
        }

        string ans = "";
        lcpUtil(root, ans);
        return ans;
    }
};

string LongestCommonPrefix1(vector<string>& arr,int n){
    string ans = "";
    for(int i = 0;i < arr[0].length();i++){
        char a = arr[0][i];
        bool match = true;
        for(int j = 1;j < n;j++){
            if(arr[j].size() < i || a != arr[j][i]){
                match = false;
                break;
            }
        }
        if(!match){
            break;
        }else{
            ans.push_back(a);
        }
    }
    return ans;
}

int main(){
    vector<string> words = {"fool", "food", "foot"};
    Trie trie;
    
    string longestPrefix1 = LongestCommonPrefix1(words, words.size());
    cout << longestPrefix1;nl;

    string longestPrefix = trie.LongestCommonPrefix(words, words.size());
    cout << longestPrefix;nl;
    return 0;
}
