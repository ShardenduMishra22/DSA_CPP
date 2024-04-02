#include<bits/stdc++.h>
using namespace std;

#define frb(i, len) for(int i = len-1; i >= 0; i--)
#define fr(i, len) for(int i = 0; i < len; i++)
#define tas cout<<"Tell a string : ";
#define nl cout<<"\n";
#define N 1000
typedef vector<vector<string>> vvstr;
typedef vector<vector<int>> vvint;
typedef vector<string> vstr;
typedef vector<int> vint;
typedef long long int ll;
typedef const int c_int;
typedef double dbl;
int InversionCount = 0;
c_int MOD = 1e9 + 7;
c_int Mx_row = 100;
c_int Mx_col = 100;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertHead(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertTail(int data) {
        Node* newNode = new Node(data);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAtPos(int data, int pos) {
        if (pos < 1) {
            cout << "Invalid position!\n";
            return;
        }
        if (pos == 1) {
            insertHead(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* temp = head;
        int count = 1;
        while (count < pos - 1 && temp != nullptr) {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr) {
            cout << "Invalid position! Position exceeds the length of the list.\n";
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        } else {
            tail = newNode;
        }
        temp->next = newNode;
    }

    void deleteHead() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    void deleteTail() {
        if (tail == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

    void deleteAtPos(int pos) {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        if (pos < 1) {
            cout << "Invalid position!\n";
            return;
        }
        if (pos == 1) {
            deleteHead();
            return;
        }
        Node* temp = head;
        int count = 1;
        while (count < pos && temp != nullptr) {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr) {
            cout << "Invalid position! Position exceeds the length of the list.\n";
            return;
        }
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;
        }
        temp->prev->next = temp->next;
        delete temp;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        cout << "Doubly linked list: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll1;
    int choice, data, pos;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at head\n";
        cout << "2. Insert at tail\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete from head\n";
        cout << "5. Delete from tail\n";
        cout << "6. Delete from position\n";
        cout << "7. Display list\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at head: ";
                cin >> data;
                dll1.insertHead(data);
                break;
            case 2:
                cout << "Enter data to insert at tail: ";
                cin >> data;
                dll1.insertTail(data);
                break;
            case 3:
                cout << "Enter position to insert: ";
                cin >> pos;
                cout << "Enter data to insert at position " << pos << ": ";
                cin >> data;
                dll1.insertAtPos(data, pos);
                break;
            case 4:
                dll1.deleteHead();
                break;
            case 5:
                dll1.deleteTail();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> pos;
                dll1.deleteAtPos(pos);
                break;
            case 7:
                dll1.display();
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (choice != 8);

    return 0;
}
