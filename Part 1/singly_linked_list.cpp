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


class node {
public:
    int data;
    node* next;
    node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    node* head;
    node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertHead(int data) {
        node* newnode = new node(data);
        if (head == nullptr) {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
    }

    void insertTail(int data) {
        node* newnode = new node(data);
        if (tail == nullptr) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void insertPosition(int data, int posn) {
        if (posn < 1) {
            cout << "Invalid position! Position must be greater than or equal to 1." << "\n";
            return;
        }
        if (posn == 1) {
            insertHead(data);
            return;
        }
        node* newnode = new node(data);
        node* temp = head;
        int i = 1;
        while (i < posn - 1 && temp != nullptr) {
            temp = temp->next;
            i += 1;
        }
        if (temp == nullptr) {
            cout << "Invalid position! Position exceeds the length of the list." << "\n";
            delete newnode;
            return;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        if (temp == tail) {
            tail = newnode;
        }
    }

    void deletePosition(int posn) {
        if (head == nullptr && tail == nullptr) {
            cout << "Empty list! Nothing to delete." << endl;
            return;
        }
        if (posn < 1) {
            cout << "Invalid position! Position must be greater than or equal to 1." << endl;
            return;
        }
        node* temp = head;
        if (posn == 1) {
            head = head->next;
            delete temp;
            if (head == nullptr) {
                tail = nullptr;
            }
            return;
        }
        int i = 1;
        node* prev = nullptr;
        while (i < posn && temp != nullptr) {
            prev = temp;
            temp = temp->next;
            i += 1;
        }
        if (temp == nullptr) {
            cout << "Invalid position! Position does not exist." << endl;
            return;
        }
        prev->next = temp->next;
        if (temp == tail) {
            tail = prev;
        }
        delete temp;
    }

    void display() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        node* temp = head;
        while (temp != nullptr) {
            node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
        tail = nullptr;
    }
};

int main() {
    LinkedList myList;
    int choice, value, position;

    do {
        cout << "\nLinked List Menu\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Position\n";
        cout << "5. Display List\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> value;
                myList.insertHead(value);
                break;
            case 2:
                cout << "Enter value to insert at tail: ";
                cin >> value;
                myList.insertTail(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position to insert: ";
                cin >> position;
                myList.insertPosition(value, position);
                break;
            case 4:
                cout << "Enter position to delete: ";
                cin >> position;
                myList.deletePosition(position);
                break;
            case 5:
                cout << "Displaying List: ";
                myList.display();
                break;
            case 6:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
