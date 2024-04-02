#include <iostream>
using namespace std;

#define N 5

class Queue {
private:
    int *queue;
    int front, rear;

public:
    Queue() {
        queue = new int[N];
        front = -1;
        rear = -1;
    }

    void enqueue() {
        int a;
        cout << "Enter the number to add: ";
        cin >> a;
        if ((rear + 1) % N == front) {
            cout << "Queue is Full" << endl;
            return;
        } else if (front == -1 && rear == -1) {
            front = rear = 0;
            queue[rear] = a;
        } else {
            rear = (rear + 1) % N;
            queue[rear] = a;
        }
    }

    void dequeue() {
        if (rear == -1 && front == -1) {
            cout << "Queue is Empty" << endl;
            return;
        } else if (rear == front) {
            cout << "Dequeued element: " << queue[rear] << endl;
            rear = front = -1;
        } else {
            cout << "Dequeued element: " << queue[front] << endl;
            front = (front + 1) % N;
        }
    }

    void display() {
        if (rear == -1 && front == -1) {
            cout << "Queue is Empty" << endl;
        } else {
            int i = front;
            cout << "Queue is: ";
            while (i != rear) {
                cout << queue[i] << " ";
                i = (i + 1) % N;
            }
            cout << queue[rear] << endl;
        }
    }

    void peek() {
        if (rear == -1 && front == -1) {
            cout << "Queue is Empty" << endl;
        } else {
            cout << "Front element: " << queue[front] << endl;
        }
    }
};

int main() {
    Queue q;
    int choice;
    while (true) {
        cout << "\n1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Peek\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                q.enqueue();
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                q.peek();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
