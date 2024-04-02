#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data ;
    node* next;
    node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList{
private:
    node* head;
    node* tail;
    int size_ll;

public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        size_ll = 0;
    }

    void insrt_end(){
        int data;
        cout<<"Tell a value : ";
        cin>>data;
        node *newNode = new node(data);
        if(head == nullptr){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        size_ll++;
    }

    void insertAtTail(node* &tail, node* curr ) {
        tail -> next = curr;
        tail = curr;
    }


    node* sortList()
    {
        node* zeroHead = new node(-1);
        node* zeroTail = zeroHead;
        node* oneHead = new node(-1);
        node* oneTail = oneHead;
        node* twoHead = new node(-1);
        node* twoTail = twoHead;
        
        node* curr = head;
        
        // create separate list 0s, 1s and 2s
        while(curr != NULL) {
            int value = curr -> data;
            if(value == 0) {
                insertAtTail(zeroTail, curr);
            }
            else if(value == 1) {
                insertAtTail(oneTail, curr);
            }
            else if(value == 2) {
                insertAtTail(twoTail, curr);
            }       
            curr = curr -> next;
        }
        
        //merge 3 sublist
        
        // 1s list not empty
        if(oneHead -> next != NULL) {
            zeroTail -> next = oneHead -> next;
        }else {
            //1s list -> empty
            zeroTail -> next = twoHead -> next;
        }
        
        oneTail -> next = twoHead -> next;
        twoTail -> next = NULL;
        
        //setup head 
        head = zeroHead -> next;
        
        //delete dummy nodes
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return head;
    }
    
    void srt_0_1_2_first_approach(){
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        node* temp = head; 
        while (temp != nullptr){
            if (temp->data == 0) cnt0 += 1;
            else if (temp->data == 1) cnt1 += 1;
            else if (temp->data == 2) cnt2 += 1; 
            temp = temp->next;
        }
        temp = head;
        while (temp != nullptr){
            if(cnt0 > 0){
                temp->data = 0; cnt0 -= 1;
            }else if(cnt1 > 0){
                temp->data = 1; cnt1 -= 1;
            }else if(cnt2 > 0){
                temp->data = 2; cnt2 -= 1;
            }
            temp = temp->next;
        }
    }
    void display(){
        node* temp = head; 
        while (temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }
    ~LinkedList(){
        node*temp=head,*frwd;
        while(temp != nullptr){
            frwd = temp->next;
            delete temp;
            temp = frwd;
        }
    }
};

int main(){
    LinkedList l1;
    for(int i = 0; i < 5; ++i) {
        l1.insrt_end();
    }
    cout<<"The linked list is given by : \n";
    l1.display();
    l1.srt_0_1_2_first_approach(); // Corrected function call
    cout<<"The sorted linked list is given by : \n";
    l1.display();
}
