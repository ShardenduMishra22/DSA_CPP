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

class node{
    pb:
    int data;
    node* next;
    node(int data){
        this->next = nptr;
        this->data = data;
    }   
};

class Circular_LnkdLst{
    pv:
    node* head ;
    node* tail ;

    pb:
    Circular_LnkdLst(){
        head = nptr;
        tail = nptr;
        size_ll = 0;
    }

    void insrt_end(){
        int data;
        cout<<"Tell a value : ";
        cin>>data;
        node *newNode = new node(data);
        if(head == nptr){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    void split_two(node*& tail1, node*& head2) {
        if (head == nullptr || head->next == head) {
            cout << "List is empty or has only one element, cannot split.\n";
            return;
        }
        node *slow = head;
        node *fast = head;
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }
        tail1 = slow;
        head2 = slow->next;
        tail1->next = head;
        fast->next = head2;
    }

    void display(node*& tail1, node*& head2) {
        node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;

        temp = head2;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head2);
        cout << endl;
    }

    ~Circular_LnkdLst() {
        node* current = head;
        while (current != nptr) {
            node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    Circular_LnkdLst l1;

    node* tail1 = nullptr;
    node* head2 = nullptr;

    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at end\n";
        cout << "2. Split into two lists\n";
        cout << "3. Display lists\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                l1.insrt_end();
                cout << "Element inserted at the end.\n";
                break;
            case 2:
                l1.split_two(tail1, head2);
                cout << "List split into two.\n";
                break;
            case 3:
                cout << "Elements of the lists:\n";
                l1.display(tail1, head2);
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
