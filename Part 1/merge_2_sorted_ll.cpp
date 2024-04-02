#include <iostream>
using namespace std;

// Define the Node class
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize data and next pointer
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Define the LinkedList class
class LinkedList {
public:
    Node* head;
    Node* tail;

public:
    // Constructor to initialize head and tail
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Function to insert a node at the end of the linked list
    void insertEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Function to merge two sorted linked lists
    Node* mergeSortedLists(Node* head1, Node* head2) {
        Node* mergedHead = nullptr;
        Node* mergedTail = nullptr;

        // Loop until one of the lists becomes empty
        while (head1 != nullptr && head2 != nullptr) {
            // Compare the data of the nodes and append the smaller one to the merged list
            if (head1->data <= head2->data) {
                if (mergedHead == nullptr) {
                    mergedHead = head1;
                    mergedTail = head1;
                } else {
                    mergedTail->next = head1;
                    mergedTail = mergedTail->next;
                }
                head1 = head1->next;
            } else {
                if (mergedHead == nullptr) {
                    mergedHead = head2;
                    mergedTail = head2;
                } else {
                    mergedTail->next = head2;
                    mergedTail = mergedTail->next;
                }
                head2 = head2->next;
            }
        }

        // Append the remaining nodes of the non-empty list to the merged list
        if (head1 != nullptr) {
            mergedTail->next = head1;
        } else {
            mergedTail->next = head2;
        }

        return mergedHead;
    }

    // Function to print the linked list
    void printList(Node* head) {
        while (head != nullptr) {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main() {
    // Create two linked lists
    LinkedList l1, l2;

    // Insert elements into the first linked list
    l1.insertEnd(1);
    l1.insertEnd(3);
    l1.insertEnd(5);

    // Insert elements into the second linked list
    l2.insertEnd(2);
    l2.insertEnd(4);
    l2.insertEnd(6);

    // Merge the sorted linked lists
    Node* mergedHead = l1.mergeSortedLists(l1.head, l2.head);

    // Print the merged linked list
    cout << "Merged Linked List: ";
    l1.printList(mergedHead);

    return 0;
}
