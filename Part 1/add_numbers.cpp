#include<bits/stdc++.h>
using namespace std;

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
public:
    node* head;
    node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insrt_end(int data) {
        node* newNode = new node(data);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    node* reverse(node* head) {
        node* curr = head;
        node* prev = nullptr;
        node* frwd;
        while (curr != nullptr) {
            frwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = frwd;
        }
        return prev;
    }

    node* add_ll(node* head1, node* head2) {
        head1 = reverse(head1);
        head2 = reverse(head2);

        node* res_head = nullptr;
        node* res_tail = nullptr;
        int carry = 0;

        while (head1 != nullptr || head2 != nullptr || carry) {
            int sum = carry;
            if (head1 != nullptr) {
                sum += head1->data;
                head1 = head1->next;
            }
            if (head2 != nullptr) {
                sum += head2->data;
                head2 = head2->next;
            }

            carry = sum / 10;
            sum %= 10;

            node* newNode = new node(sum);
            if (res_head == nullptr) {
                res_head = res_tail = newNode;
            } else {
                res_tail->next = newNode;
                res_tail = newNode;
            }
        }

        return reverse(res_head);
    }

    ~LinkedList() {
        node* temp = head;
        while (temp != nullptr) {
            node* frwd = temp->next;
            delete temp;
            temp = frwd;
        }
    }
};

int main() {
    LinkedList l1, l2;
    l1.insrt_end(2);
    l1.insrt_end(4);
    l1.insrt_end(5);

    l2.insrt_end(5);
    l2.insrt_end(5);

    node* h1 = l1.add_ll(l1.head, l2.head);
    node* temp = h1;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
