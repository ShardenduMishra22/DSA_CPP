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
c_int MOD = 1e9 + 7;
c_int Mx_row = 100;
c_int Mx_col = 100;
int InversionCount = 0;
int size_ll = 0;

class node{
    pb:
    int data;
    node* next;
    node(int data){
        this->data = data;
        this->next = nptr;
    }
};

class LnkdLst{
    pv:
    node* head;
    node* tail;

    pb:
    LnkdLst(){
        head = nptr;
        tail = nptr;
    }

    void add_posn(int data, int posn){
        node* newNode = new node(data);
        if (posn < 1 || posn > size_ll + 1){
            cout<<"Invalid Position \n";
            return;
        }else{
            if (posn == 1){
                if(head == nptr){
                    head = tail = newNode;
                }else{
                    newNode->next = head;
                    head = newNode;
                }
                size_ll += 1;
                cout<<"The size of the linked list is : "<<size_ll<<"\n";
                cout<<"You can add the last element at "<<size_ll+1<<" position \n";
            }else if (posn == size_ll ){
                tail->next = newNode;
                tail = newNode;                
            }else{
                int i = 1;
                node* temp = head;
                while (i != posn-1){
                    temp = temp->next;
                    i += 1;
                }
                newNode->next = temp->next;
                temp->next = newNode;
                size_ll += 1;
                cout<<"The size of the linked list is : "<<size_ll<<"\n";
                cout<<"You can add the last element at "<<size_ll+1<<" position \n";
            }
        }
    }

    void middle(){
        if (head == nptr) return ;
        if (head ->next == nptr) cout<<"The middle element is : "<<head->data; return;
        node* slow = nptr;
        node* fast = nptr;
        slow = fast = head;
        while (fast != nptr && fast->next != nptr){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        cout<<"The middle element is : "<<slow->data;
    }

    void display(){
        if(head == nptr){
            cout << "Linked List is empty\n";
            return;
        }
        node* temp = head;
        while(temp != nptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~LnkdLst() {
        node* current = head;
        while (current != nptr) {
            node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LnkdLst list;
    int choice, data, pos;

    while (true) {
        cout << "\nLinked List Menu:\n";
        cout << "1. Add element at a position\n";
        cout << "2. Find middle element\n";
        cout << "3. Display elements\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to add: ";
                cin  >> data;
                cout << "Enter position to add: ";
                cin  >> pos;
                list.add_posn(data, pos);
                break;
            case 2:
                cout << "Finding middle element:\n";
                list.middle();
                break;
            case 3:
                cout << "Elements of the linked list: ";
                list.display();
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
