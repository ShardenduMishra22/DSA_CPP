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

class node{
    pb:
    int data;
    node* next;
    node(int data){
        this->data = data;
        this->next = nptr;
    }
};

class LinkedList{
    pb:
    node* head;
    node* tail;
    LinkedList(){
        head = nptr;
        tail = nptr;
        size_ll = 0;
    }

    void insrt_end(int data){
        // int data;
        // cout<<"Tell a value : ";
        // cin>>data;
        node *newNode = new node(data);
        if(head == nullptr){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        size_ll++;
    }

    node* getMiddle(node* head){
        node*slow = head;
        node*fast = head;
        while(fast != nptr && fast->next != nptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    node* reverse(node* head){
        node* curr = head;
        node* prev = nptr;
        node* frwd ; 
        while (curr != nptr){
            frwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = frwd;
        }
        return prev;
    }

    bool isPalindrome(){
        if (head == nullptr || head->next == nullptr) {
            return true; // Empty list or single node is palindrome
        }
            
        node* middle = getMiddle(head);
        node* secondHalf = reverse(middle->next);
        middle->next = nullptr; // Break the list into two halves
        
        node* head1 = head;
        node* head2 = secondHalf;

        while (head2 != nullptr) {
            if (head1->data != head2->data) {
                return false;
            }
            head1 = head1-> next;
            head2 = head2->next;
        }
        return true;
    }


    ~LinkedList(){
        node*temp=head,*frwd;
        while(temp != nptr){
            frwd = temp->next;
            delete temp;
            temp = frwd;
        }
    }
};

int main(){
    LinkedList l1;
    l1.insrt_end(1);
    l1.insrt_end(2);
    l1.insrt_end(3);
    l1.insrt_end(4);
    l1.insrt_end(5);
    l1.insrt_end(4);
    l1.insrt_end(3);
    l1.insrt_end(2);
    l1.insrt_end(1);

    if (l1.isPalindrome()) cout<<"It's a palindrome !";
    else cout<<"It's not a palindrome !";
}