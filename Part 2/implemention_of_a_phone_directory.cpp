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

    void PrintSuggestion(TrieNode*curr,vstr&temp,string prefix){
        if(curr->isTerminal) temp.push_back(prefix);
        
        for(char i = 'a';i <= 'z';i++){
            TrieNode*next = curr->children[i - 'a'];
            if(next != NULL){
                prefix.push_back(i);
                PrintSuggestion(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }

    vvstr GetSuggestion(string str){
        TrieNode*prev = root;
        vvstr ans;
        string prefix = "";
        for (int i=0;i<str.length();i++){
            char LastChar = str[i];
            prefix.push_back(LastChar);
            TrieNode*curr = prev->children[LastChar - 'a'];
            if(curr == NULL){
                break;
            }
            vstr temp;
            PrintSuggestion(curr,temp,prefix);

            ans.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return ans;
    }

    vvstr PhoneDirectory(string&QueryStr){
        Trie*t = new Trie();

        vstr CnctList = {"John", "Johnny", "Jane", "Janet", "James"};

        for(int i=0;i<CnctList.size();i++){
            string str = CnctList[i];
            t->Insert(str);
        }
        return t->GetSuggestion(QueryStr);
    }

};

int main() {
    Trie trie;

    string query = "Jan";
    vvstr suggestions = trie.PhoneDirectory(query);

    cout << "Suggestions for '" << query << "':" << endl;
    for (const auto& suggestionList : suggestions) {
        for (const auto& suggestion : suggestionList) {
            cout << suggestion << endl;
        }
    }

    return 0;
}
