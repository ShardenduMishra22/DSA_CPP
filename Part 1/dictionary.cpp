#include<bits/stdc++.h>
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
#define pv public // Corrected access specifier for constructor
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
    pb:
    int data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    pb:
    TrieNode* root;
public: // Made constructor public
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
};

int main() {
    Trie trie;

    trie.Insert("hello");
    trie.Insert("world");
    trie.Insert("hi");
    trie.Insert("hey");

    cout << "Search results:" << endl;
    cout << "hello : " << (trie.Search("hello") ? "Found" : "Not found") << endl;
    cout << "world : " << (trie.Search("world") ? "Found" : "Not found") << endl;
    cout << "hi : "    << (trie.Search("hi") ? "Found" : "Not found")    << endl;
    cout << "he : "    << (trie.Search("he") ? "Found" : "Not found")   << endl;
    cout << "bye : "   << (trie.Search("bye") ? "Found" : "Not found")   << endl;

    return 0;
}
