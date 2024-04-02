#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* findMid(Node* head) {
        Node* slow = head;
        Node* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node* merge(Node* left, Node* right) {
        if (left == nullptr) return right;
        if (right == nullptr) return left;
    
        Node* ans = nullptr;
        if (left->data <= right->data) {
            ans = left;
            ans->next = merge(left->next, right);
        } else {
            ans = right;
            ans->next = merge(left, right->next);
        }
        return ans;
    }

    Node* mergeSort(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        Node* mid = findMid(head);
        Node* left = head;
        Node* right = mid->next;
        mid->next = nullptr;
        left = mergeSort(left);
        right = mergeSort(right);
        return merge(left, right);
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    // Populate the linked list
    list.insertEnd(3);
    list.insertEnd(7);
    list.insertEnd(2);
    list.insertEnd(5);
    list.insertEnd(1);
    list.insertEnd(6);
    
    cout << "Original linked list: ";
    list.display();
    
    // Call merge sort function
    list.head = list.mergeSort(list.head);

    cout << "Sorted linked list: ";
    list.display();

    return 0;
}
