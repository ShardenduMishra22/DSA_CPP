#include <bits/stdc++.h>
using namespace std;
    
#define nptr nullptr
    
// Definition for a node.
class node {
public:
    int val;
    node* next;
    node* random;
    
    node(int _val) {
        val = _val;
        next = nptr;
        random = nptr;
    }
};  
    
class LinkedList {
    public:
    node* head;
    node* tail;
    
    LinkedList() {
        head = nptr;
        tail = nptr;
    }
    
    // Function to insert a new node at the end of the linked list
    void insertEnd(int data) {
        node* newNode = new node(data);
        if (head == nptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    // Function to print the linked list
    void printList() {
        node* curr = head;
        while (curr != nptr) {
            cout << "Value: " << curr->val;
            if (curr->random != nptr)
                cout << ", Random: " << curr->random->val;
            else
                cout << ", Random: NULL";
            cout << endl;
            curr = curr->next;
        }
    }
    
    // Function to clone the linked list with random pointer
    node* cloneLinkedList(node* head) {
        unordered_map<node*, node*> old_new;
        node* original_node = head;
        while (original_node != nptr) {
            node* new_node = new node(original_node->val);
            old_new[original_node] = new_node;
            original_node = original_node->next;
        }

        original_node = head;
        while (original_node != nptr) {
            node* cloned_node = old_new[original_node];
            cloned_node->next = old_new[original_node->next];
            cloned_node->random = old_new[original_node->random];
            original_node = original_node->next;
        }
        return old_new[head];
    }
};

int main() {
    LinkedList l;
    l.insertEnd(1);
    l.insertEnd(2);
    l.insertEnd(3);
    l.insertEnd(4);

    // Assigning random pointers manually for demonstration
    l.head->random = l.head->next->next; // Random pointer of node 1 points to node 3
    l.head->next->random = l.head->next->next->next; // Random pointer of node 2 points to node 4
    l.head->next->next->random = l.head; // Random pointer of node 3 points to node 1
    l.head->next->next->next->random = l.head->next; // Random pointer of node 4 points to node 2

    cout << "Original linked list with random pointers:" << endl;
    l.printList();

    // Cloning the linked list
    LinkedList clonedList;
    clonedList.head = l.cloneLinkedList(l.head);

    cout << "\nCloned linked list with random pointers:" << endl;
    clonedList.printList();

    return 0;
}
