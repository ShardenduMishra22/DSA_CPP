//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int s, int n, int m){
        if(n < m)
            return -1;
            
        int sunday = s/7;
        int buyDay = s - sunday;
        int ttl = s*m;
        int ans=0;
        
        if(ttl % n == 0)
            ans = ttl/n;
        else
            ans = ttl/n + 1;
        
        if(ans <= buyDay)
            return ans;
        return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends