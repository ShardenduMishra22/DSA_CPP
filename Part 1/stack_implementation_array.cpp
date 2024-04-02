#include <iostream>
using namespace std;

#define MAX_SIZE 1000

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1; // Initialize top index to -1 to indicate an empty stack
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow: Cannot push element, stack is full." << endl;
            return;
        }
        arr[++top] = value; // Increment top and insert element into the stack
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    // Function to pop an element from the stack
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow: Cannot pop element, stack is empty." << endl;
            return;
        }
        cout << "Popped " << arr[top--] << " from the stack." << endl; // Decrement top to remove element
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return (top < 0); // If top is less than 0, stack is empty
    }

    // Function to return the top element of the stack without removing it
    int peek() {
        if (top < 0) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return arr[top]; // Return the element at the top of the stack
    }
};

int main() {
    Stack stack;

    // Push elements onto the stack
    stack.push(5);
    stack.push(10);
    stack.push(15);

    // Display the top element of the stack
    cout << "Top element of the stack: " << stack.peek() << endl;

    // Pop elements from the stack
    stack.pop();
    stack.pop();
    stack.pop();

    // Check if the stack is empty
    if (stack.isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }

    return 0;
}
