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
        this->next = nptr;
    }
};

class LnkdLst {
private:
    node* head;
    node* tail; // New tail pointer added
    int size_ll;

public:
    LnkdLst() {
        head = nptr;
        tail = nptr; // Initialize tail to nptr
        size_ll = 0;
    }

    void add_posn(int data, int posn) {
        node* newNode = new node(data);
        if (posn < 1 || posn > size_ll + 1) {
            cout << "Invalid Position \n";
            return;
        } else {
            if (posn == 1) {
                if (head == nptr) {
                    head = tail = newNode; // Update tail when adding the first node
                } else {
                    newNode->next = head;
                    head = newNode;
                }
                size_ll += 1;
            } else if (posn == size_ll) {
                tail->next = newNode;
                tail = newNode; // Update tail when adding at the end
            } else {
                int i = 1;
                node* temp = head;
                while (i != posn - 1) {
                    temp = temp->next;
                    i += 1;
                }
                newNode->next = temp->next;
                temp->next = newNode;
                size_ll += 1;
            }
        }
    }
 
    void rmv_srt() {
        if (head == nptr) {
            cout << "It's empty already!";
            return;
        }
        node* curr = head;   
        while (curr != nptr && curr->next != nptr){
            if( curr->data == curr->next->data ){
                delete curr->next;
                curr->next = curr->next->next;
            }else{
                curr = curr->next;
            }
        }
    }

    // Function to display the linked list
    void display() {
        node* temp = head;
        while (temp != nptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        // tail->next  = head->next->next;
    } 
};

int main() {
    LnkdLst list;
    int choice, data, pos;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add element\n";
        cout << "2. Display elements\n";
        cout << "3. Remove Duplicate from sorted \n";
        // cout << "4. Remove Duplicate from un-sorted\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to add: ";
                cin >> data;
                cout << "Enter position to add: ";
                cin >> pos;
                list.add_posn(data, pos);
                break;
            case 2:
                cout << "Elements of the linked list: ";
                list.display();
                break;
            case 3:
                cout << "Remove Duplicate from sorted ll \n";
                list.rmv_srt();
                break;
            case 4:
                cout << "Exiting program.\n";
                exit(0);
            default:
                cout << "Invalid choice! Please enter again.\n";
        }
    }
    return 0;
}
