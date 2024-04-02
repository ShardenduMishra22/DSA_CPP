#include <iostream>
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

class LnkdLst {
private:
    node* head;
    node* tail; // New tail pointer added
    int size_ll;

public:
    LnkdLst() {
        head = nullptr;
        tail = nullptr; // Initialize tail to nullptr
        size_ll = 0;
    }

    void add_posn(int data, int posn) {
        node* newNode = new node(data);
        if (posn < 1 || posn > size_ll + 1) {
            cout << "Invalid Position \n";
            return;
        } else {
            if (posn == 1) {
                if (head == nullptr) {
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

    // Function to detect a loop using Floyd's Cycle Detection Algorithm
    node* floydDetectLoop() {
        if (head == nullptr)
            return nullptr;

        node* slow = head;
        node* fast = head;

        while (slow != nullptr && fast != nullptr) {
            fast = fast->next;
            if (fast != nullptr) {
                fast = fast->next;
            }
            slow = slow->next;
            if (slow == fast) {
                return slow;
            }
        }

        return nullptr;
    }

    // Function to get the starting node of the loop
    node* getLoopStartNode() {
        if (head == nullptr)
            return nullptr;

        node* intersection = floydDetectLoop();

        if (intersection == nullptr)
            return nullptr;

        node* slow = head;

        while (slow != intersection) {
            slow = slow->next;
            intersection = intersection->next;
        }

        return slow;
    }

    // Function to remove the loop from the linked list
    void removeLoop() {
        node* startOfLoop = getLoopStartNode();
        if (startOfLoop == nullptr)
            return;

        node* temp = startOfLoop;
        while (temp->next != startOfLoop) {
            temp = temp->next;
        }
        temp->next = nullptr;
    }

    // Function to display the linked list
    void display() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        tail->next  = head->next->next;
    } 
};

int main() {
    LnkdLst list;
    int choice, data, pos;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add element\n";
        cout << "2. Display elements\n";
        cout << "3. Remove Loop\n";
        cout << "4. Get Loop Start Node\n";
        cout << "5. Exit\n";
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
                list.removeLoop();
                cout << "Loop removed successfully.\n";
                break;
            case 4: {
                node* startNode = list.getLoopStartNode();
                if (startNode != nullptr) {
                    cout << "Start node of the loop: " << startNode->data << endl;
                } else {
                    cout << "There is no loop in the linked list.\n";
                }
                break;
            }
            case 5:
                cout << "Exiting program.\n";
                exit(0);
            default:
                cout << "Invalid choice! Please enter again.\n";
        }
    }
    return 0;
}
