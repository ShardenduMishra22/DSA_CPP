//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{
public:
    vector<int> candyStore(int candy[], int N, int K){
        vector<int> candies(candy, candy + N); 

        sort(candies.begin(), candies.end()); 
        
        int mn = 0; 
        int mx = 0; 
        
        
        int end = candies.size();
        for(int i = 0; i < end; i++){
            mn += candies[i];
            end -= K; 
        }
        
        reverse(candies.begin(), candies.end()); 
        end = candies.size();
        for(int i = 0; i < end; i++){
            mx += candies[i];
            end -= K; 
        }
        
        return {mn, mx}; 
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends