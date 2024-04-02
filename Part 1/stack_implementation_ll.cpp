#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top; 

public:
    Stack() {
        top = nullptr; 
    }

    void push(int value) {
        Node* newNode = new Node(value); 
        if (top == nullptr) {
            top = newNode; 
        } else {
            newNode->next = top; 
            top = newNode; 
        }
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow: Cannot pop element, stack is empty." << endl;
            return;
        }
        Node* temp = top;  
        top = top->next; 
        cout << "Popped " << temp->data << " from the stack." << endl;
        delete temp; 
    }

    bool isEmpty() {
        return (top == nullptr); 
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return top->data; 
    }
};

int main() {
    Stack stack;

 
    stack.push(5);
    stack.push(10);
    stack.push(15);


    cout << "Top element of the stack: " << stack.peek() << endl;

 
    stack.pop();
    stack.pop();
    stack.pop();


    if (stack.isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }

    return 0;
}
