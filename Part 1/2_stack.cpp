#include <iostream>
using namespace std;

class TwoStacks {
private:
    int* arr;
    int size;
    int top1;
    int top2;
public:
    TwoStacks(int n) {
        size = n;
        arr = new int[size];
        top1 = -1; // top pointer for stack 1
        top2 = size; // top pointer for stack 2
    }

    void push1(int x) {
        if (top2 - top1 > 1) {
            arr[++top1] = x;
        } else {
            cout << "Stack Overflow for Stack 1\n";
            exit(1);
        }
    }

    void push2(int x) {
        if (top2 - top1 > 1) {
            arr[--top2] = x;
        } else {
            cout << "Stack Overflow for Stack 2\n";
            exit(1);
        }
    }

    int pop1() {
        if (top1 >= 0) {
            return arr[top1--];
        } else {
            cout << "Stack Underflow for Stack 1\n";
            exit(1);
        }
    }

    int pop2() {
        if (top2 < size) {
            return arr[top2++];
        } else {
            cout << "Stack Underflow for Stack 2\n";
            exit(1);
        }
    }
};

int main() {
    TwoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);

    cout << "Popped element from stack 1: " << ts.pop1() << endl;
    ts.push2(40);
    cout << "Popped element from stack 2: " << ts.pop2() << endl;

    return 0;
}