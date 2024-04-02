// Explain this 
#include<bits/stdc++.h>
using namespace std;

struct petrolPump{
    int petrol;
    int distance;
};

class Solution{
  public:
  
    int tour(petrolPump p[],int n){
       int deficit = 0;
       int balance = 0;
       int start = 0;
       
       for(int i=0; i<n; i++) {
           balance += p[i].petrol - p[i].distance;
           if(balance < 0) {
               start = i+1;
               deficit += balance;
               balance = 0;
           }
       }
       if(balance + deficit >=0) 
            return start;
        return -1;
    }
};


int main(){
    petrolPump p[] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}};
    int n = sizeof(p) / sizeof(p[0]);
    Solution obj;
    cout << obj.tour(p, n); 
    return 0;
}
