#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    CircularLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void addAtHead(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
        size++;
        cout << "Inserted " << value << " at the head." << endl;
    }

    void addAtPosition(int value, int position) {
        if (position < 1 || position > size + 1) {
            cout << "Invalid position. Cannot insert." << endl;
            return;
        }
        if (position == 1) {
            addAtHead(value);
            return;
        }
        if (position == size + 1) {
            addAtTail(value);
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;

        Node* prev = nullptr;
        Node* curr = head;
        int count = 1;

        while (count < position) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = newNode;
        newNode->next = curr;
        size++;
        cout << "Inserted " << value << " at position " << position << "." << endl;
    }

    void addAtTail(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
        size++;
        cout << "Inserted " << value << " at the tail." << endl;
    }

    void deleteHead() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        cout << "Deleted head node." << endl;
    }

    void deleteAtPosition(int position) {
        if (position < 1 || position > size) {
            cout << "Invalid position. Cannot delete." << endl;
            return;
        }
        if (position == 1) {
            deleteHead();
            return;
        }

        Node* prev = nullptr;
        Node* curr = head;
        int count = 1;

        while (count < position) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;
        delete curr;
        size--;
        cout << "Deleted node at position " << position << "." << endl;
    }

    void deleteTail() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            temp->next = head;
            delete tail;
            tail = temp;
        }
        size--;
        cout << "Deleted tail node." << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList myList;
    int choice, value, position;

    do {
        cout << "\nCircular Linked List Menu\n";
        cout << "1. Add at Head\n";
        cout << "2. Add at Position\n";
        cout << "3. Add at Tail\n";
        cout << "4. Delete Head\n";
        cout << "5. Delete at Position\n";
        cout << "6. Delete Tail\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> value;
                myList.addAtHead(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position to insert: ";
                cin >> position;
                myList.addAtPosition(value, position);
                break;
            case 3:
                cout << "Enter value to insert at tail: ";
                cin >> value;
                myList.addAtTail(value);
                break;
            case 4:
                myList.deleteHead();
                break;
            case 5:
                cout << "Enter position to delete: ";
                cin >> position;
                myList.deleteAtPosition(position);
                break;
            case 6:
                myList.deleteTail();
                break;
            case 7:
                myList.display();
                break;
            case 8:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
