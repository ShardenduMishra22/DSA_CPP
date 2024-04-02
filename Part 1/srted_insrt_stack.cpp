#include <iostream>
#include <stack>
using namespace std;

void sortInsert(int val, stack<int>& st) {
    if (st.empty() || st.top() < val) {
        st.push(val);
        return;
    }
    int temp = st.top();
    st.pop();
    sortInsert(val, st);
    st.push(temp);
}

void sortStack(stack<int>& st) {
    if (st.empty()) {
        return;
    }
    int val = st.top();
    st.pop();
    sortStack(st);
    sortInsert(val, st);
}

int main() {
    stack<int> st;
    cout << "Enter 5 integers:\n";
    for (int i = 0; i < 5; ++i) {
        int num;
        cin >> num;
        st.push(num);
    }

    sortStack(st);

    cout << "Sorted stack: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
