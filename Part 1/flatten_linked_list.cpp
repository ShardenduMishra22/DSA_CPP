#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* child;

    node(int data) {
        this->data = data;
        this->next = nullptr;
        this->child = nullptr;
    }
};

class LinkedList {
public:
    node* head;

    LinkedList() {
        head = nullptr;
    }

    void insertEnd(int data) {
        node* newnode = new node(data);
        if (head == nullptr) {
            head = newnode;
        } else {
            node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    // Flatten the linked list
    void flatten() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        node* temp1 = head;
        while (temp1 != nullptr) {
            if (temp1->child != nullptr) {
                node* temp2 = temp1->child;
                while (temp2->next != nullptr) {
                    temp2 = temp2->next;
                }
                temp2->next = temp1->next;
                temp1->next = temp1->child;
                temp1->child = nullptr;
            }
            temp1 = temp1->next;
       }
    }


    void display() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    // Populate the linked list with child nodes
    list.insertEnd(1);
    list.head->child = new node(3);
    list.head->child->next = new node(4);
    list.head->child->next->child = new node(7);
    list.head->child->next->child->next = new node(9);
    list.insertEnd(2);
    list.head->next->child = new node(5);
    list.insertEnd(6);
    list.insertEnd(8);

    cout << "Original linked list: ";
    list.display();

    // Flatten the linked list
    list.flatten();

    cout << "Flattened linked list: ";
    list.display();

    return 0;
}
