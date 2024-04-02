#include<bits/stdc++.h>
using namespace std;

#define frb(i, len) for(int i = len-1; i >= 0; i--)
#define fr(i, len) for(int i = 0; i < len; i++)
#define tas cout<<"Tell a string : ";
#define nl cout<<"\n";
#define nptr nullptr
#define pr protected
#define pv private
#define pb public
#define N 1000
typedef vector<vector<string>> vvstr;
typedef vector<vector<int>> vvint;
typedef vector<string> vstr;
typedef vector<int> vint;
typedef long long int ll;
typedef const int c_int;
typedef double dbl;
int InversionCount = 0;
int size_ll = 0;
c_int MOD = 1e9 + 7;
c_int Mx_row = 100;
c_int Mx_col = 100;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = nullptr;
    }
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

    bool loop2(){
        node* temp = head;
        map<int,bool> loop_chck;
        while(temp != nptr){
            if(loop_chck[temp->data] == true){
                cout<<"Loop detected !";
                return true;
            }
            loop_chck[temp->data] = true;
            temp = temp->next;
        }
        cout<<"There is no loop !";
        return false;
    }

    bool loop(){
        if (head == nptr) return false;
        node* temp = head->next;
        while(temp != head && temp != nptr){
            temp = temp->next;
        }
        if(temp == head){
            cout<<"There is a loop \n";
            return true;
        }else{
            cout<<"No loop \n";
            return false;
        }
    }

    void display() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        nl;
        // to add a loop 
        tail->next = head->next->next->next;
    }

};

int main() {
    LinkedList list;
    int choice, data, pos;

    while (true) {
        cout << "\nLinked List Menu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at the end\n";
        cout << "3. Insert at a specific position\n";
        cout << "4. Delete at a specific position\n";
        cout << "5. Display elements\n";
        cout << "6. Check for loop\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                list.insertHead(data);
                break;
            case 2:
                cout << "Enter data to insert at the end: ";
                cin >> data;
                list.insertTail(data);
                break;
            case 3:
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position to insert: ";
                cin >> pos;
                list.insertPosition(data, pos);
                break;
            case 4:
                cout << "Enter position to delete: ";
                cin >> pos;
                list.deletePosition(pos);
                break;
            case 5:
                cout << "Elements of the linked list: ";
                list.display();
                break;
            case 6:
                list.loop2();
                break;
            case 7:
                cout << "Exiting program.\n";
                exit(0);
            default:
                cout << "Invalid choice! Please enter again.\n";
        }
    }

    return 0;
}