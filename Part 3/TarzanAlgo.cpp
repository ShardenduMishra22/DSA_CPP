#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int time = 0;
    stack<int> st;
    vector<bool> inStack;
    
    void tarjanDFS(int u, vector<int>& disc, vector<int>& low, vector<vector<int>>& adj, vector<vector<int>>& result) {
        disc[u] = low[u] = ++time;
        st.push(u);
        inStack[u] = true;
        
        for (int v : adj[u]) {
            if (disc[v] == -1) {
                tarjanDFS(v, disc, low, adj, result);
                low[u] = min(low[u], low[v]);
            } else if (inStack[v]) {
                low[u] = min(low[u], disc[v]);
            }
        }
        
        if (low[u] == disc[u]) {
            vector<int> component;
            while (true) {
                int v = st.top();
                st.pop();
                inStack[v] = false;
                component.push_back(v);
                if (v == u) break;
            }
            result.push_back(component);
        }
    }

public:
    vector<vector<int>> findSCCs(int V, vector<vector<int>>& adj) {
        vector<int> disc(V, -1), low(V, -1);
        vector<vector<int>> result;
        inStack.assign(V, false);
        
        for (int i = 0; i < V; ++i) {
            if (disc[i] == -1) {
                tarjanDFS(i, disc, low, adj, result);
            }
        }
        
        return result;
    }
};