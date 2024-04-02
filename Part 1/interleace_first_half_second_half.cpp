#include<bits/stdc++.h>
using namespace std;

int main(){
    // Declare the input and auxiliary queues
    queue<int> q1, q2, q3;

    // Input 11 integers into q1
    for(int i = 0; i < 11; i++) {
        int a;
        cin >> a;
        q1.push(a);
    }

    // Move the first half of q1 to q2
    int len = q1.size();
    int half_len = len / 2;
    for(int i = 0; i < half_len; i++) {
        q2.push(q1.front());
        q1.pop();
    }

    // Interleave the elements of q1 and q2 into q3
    while(!q1.empty() && !q2.empty()){
        q3.push(q2.front());
        q2.pop();
        q3.push(q1.front());
        q1.pop();
    }

    // If q1 still has elements, move them to q3
    while(!q1.empty()){
        q3.push(q1.front());
        q1.pop();
    }

    // If q2 still has elements, move them to q3
    while(!q2.empty()){
        q3.push(q2.front());
        q2.pop();
    }

    // Print the interleaved queue q3
    while(!q3.empty()){
        cout << q3.front() << " ";
        q3.pop();
    }

    return 0;
}
