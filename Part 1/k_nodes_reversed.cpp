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
class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

Node* kReverse(Node* head, int k) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* next = nullptr;
    Node* curr = head;
    Node* prev = nullptr;
    int count = 0;
    while (curr != nullptr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next != nullptr) {
        head->next = kReverse(next, k);
    }
    return prev;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int choice;
    
    while (true) {
        cout << "\nLinked List Menu:\n";
        cout << "1. Create linked list\n";
        cout << "2. Reverse every k nodes\n";
        cout << "3. Display linked list\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                int n;
                cout << "Enter the number of nodes: ";
                cin >> n;
                cout << "Enter the data for each node:\n";
                Node* temp = nullptr;
                Node* last = nullptr;
                for (int i = 0; i < n; i++) {
                    int data;
                    cin >> data;
                    Node* newNode = new Node(data);
                    if (head == nullptr) {
                        head = newNode;
                    } else {
                        temp->next = newNode;
                    }
                    temp = newNode;
                    last = temp;
                }
                break;
            }
            case 2: {
                if (head == nullptr) {
                    cout << "Linked list is empty. Create a linked list first.\n";
                } else {
                    int k;
                    cout << "Enter the value of k for reversing: ";
                    cin >> k;
                    head = kReverse(head, k);
                    cout << "Linked list after reversing every " << k << " nodes: ";
                    display(head);
                }
                break;
            }
            case 3: {
                if (head == nullptr) {
                    cout << "Linked list is empty. Create a linked list first.\n";
                } else {
                    cout << "Linked list: ";
                    display(head);
                }
                break;
            }
            case 4: {
                cout << "Exiting program.\n";
                exit(0);
            }
            default:
                cout << "Invalid choice! Please enter again.\n";
        }
    }

    return 0;
}