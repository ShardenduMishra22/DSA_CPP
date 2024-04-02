#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int r;
    int f;
    int size;

public:
    Queue() {
        size = 5;
        arr = new int[size];
        f = -1;
        r = -1;
    }

    void enqueue(int data) {
        if (r == size - 1) {
            cout << "Queue is full" << endl;
            return;
        } else {
            if (f == -1 && r == -1){
                f = r = 0;
                arr[r] = data;
            }else{
                r += 1;
                arr[r] = data;
            }
            cout << "Enqueued " << data << endl; 
        }
    }

    void dequeue(){
        if(f == r){
            cout << "Queue is empty" << endl;
            return;
        } else {
            int dequeuedValue = arr[f]; 
            if(r == 0){
                f = r = -1;
            } else {
                f += 1;
            }
            cout << "Dequeued " << dequeuedValue << endl; // Print the dequeued number
        }
    }

    void display(){
        if(f == r){
            cout << "Queue is empty" << endl;
            return;
        } else {
            cout << "Queue elements: ";
            for(int i = f; i <= r; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};


int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(3);
    q.dequeue();
    q.dequeue();
    q.display();

    return 0;
}
