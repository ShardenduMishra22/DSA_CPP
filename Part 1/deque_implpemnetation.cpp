#include <iostream>
using namespace std;

#define N 5

class Deque {
private:
    int deque[N];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    void display() {
        if (front == -1 && rear == -1) {
            cout << "Deque is Empty" << endl;
            return;
        }
        int i = front;
        while (i != rear) {
            cout << deque[i] << " ";
            i = (i + 1) % N;
        }
        cout << deque[i] << endl;
    }

    void peek() {
        if (front == -1 && rear == -1) {
            cout << "Deque is Empty" << endl;
            return;
        }
        cout << deque[front] << endl;
    }

    void enqueueFront() {
        int num;
        cout << "Enter the element: ";
        cin >> num;
        if ((rear + 1) % N == front) {
            cout << "Deque is full" << endl;
            return;
        } else if (front == -1 && rear == -1) {
            front = rear = 0;
            deque[front] = num;
        } else if (front == 0) {
            front = N - 1;
            deque[front] = num;
        } else {
            front--;
            deque[front] = num;
        }
    }

    void enqueueRear() {
        int num;
        cout << "Enter the element: ";
        cin >> num;
        if ((rear + 1) % N == front) {
            cout << "Deque is full" << endl;
            return;
        } else if (front == -1 && rear == -1) {
            front = rear = 0;
            deque[rear] = num;
        } else {
            rear = (rear + 1) % N;
            deque[rear] = num;
        }
    }

    void dequeueFront() {
        if (front == -1 && rear == -1) {
            cout << "Deque is Empty" << endl;
            return;
        } else if (front == rear) {
            cout << deque[front] << " has been Dequeued" << endl;
            front = rear = -1;
        } else if (front == N - 1) {
            cout << deque[front] << " has been Dequeued" << endl;
            front = 0;
        } else {
            cout << deque[front] << " has been Dequeued" << endl;
            front = (front + 1) % N;
        }
    }

    void dequeueRear() {
        if (front == -1 && rear == -1) {
            cout << "Deque is Empty" << endl;
            return;
        } else if (front == rear) {
            cout << deque[rear] << " has been Dequeued" << endl;
            rear = front = -1;
        } else if (rear == 0) {
            cout << deque[rear] << " has been Dequeued" << endl;
            rear = N - 1;
        } else {
            cout << deque[rear] << " has been Dequeued" << endl;
            rear = (rear - 1 + N) % N;
        }
    }
};

int main() {
    Deque dq;
    int choice;
    while (true) {
        cout << "\n1. Display\n2. Peek\n3. Enqueue Front\n4. Enqueue Rear\n5. Dequeue Front\n6. Dequeue Rear\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                dq.display();
                break;
            case 2:
                dq.peek();
                break;
            case 3:
                dq.enqueueFront();
                break;
            case 4:
                dq.enqueueRear();
                break;
            case 5:
                dq.dequeueFront();
                break;
            case 6:
                dq.dequeueRear();
                break;
            case 7:
                exit(EXIT_SUCCESS);
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
    return 0;
}
