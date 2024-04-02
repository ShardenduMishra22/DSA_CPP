#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyCircularLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyCircularLinkedList() {
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
            newNode->next = head;
            newNode->prev = head;
        } else {
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode;
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

        Node* temp = head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        size++;
        cout << "Inserted " << value << " at position " << position << "." << endl;
    }

    void addAtTail(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            newNode->next = head;
            newNode->prev = head;
        } else {
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }
        size++;
        cout << "Inserted " << value << " at the tail." << endl;
    }

    void deleteHead() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
        }
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

        Node* temp = head;
        for (int i = 1; i < position; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        size--;
        cout << "Deleted node at position " << position << "." << endl;
    }

    void deleteTail() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete temp;
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
        cout << "Doubly Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    DoublyCircularLinkedList myList;
    int choice, value, position;

    do {
        cout << "\nDoubly Circular Linked List Menu\n";
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