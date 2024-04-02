#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Initialize the circular queue with a given size
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueue an element into the circular queue
    bool enqueue(int value) {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            cout << "Queue is Full" << endl;
            return false;
        } else if (front == -1) {
            front = rear = 0;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    // Dequeue an element from the circular queue
    int dequeue() {
        if (front == -1) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
        return ans;
    }
};

int main() {
    // Create a circular queue with a capacity of 5
    CircularQueue cq(5);

    // Enqueue elements into the circular queue
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);

    // Try to enqueue more elements (should fail as the queue is full)
    if (!cq.enqueue(6)) {
        cout << "Queue is full. Cannot enqueue more elements." << endl;
    }

    // Dequeue elements from the circular queue
    cout << "Dequeued element: " << cq.dequeue() << endl;
    cout << "Dequeued element: " << cq.dequeue() << endl;

    // Enqueue another element
    cq.enqueue(6);

    // Dequeue all elements from the circular queue
    while (true) {
        int element = cq.dequeue();
        if (element == -1) {
            break; // Break the loop if the queue is empty
        }
        cout << "Dequeued element: " << element << endl;
    }

    // Try to dequeue from an empty queue (should return -1)
    cout << "Dequeued element: " << cq.dequeue() << endl;

    return 0;
}
