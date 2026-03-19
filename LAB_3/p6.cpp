#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
    node *head = NULL;
    int size = 0;

public:
    void insertAtHead(int data) {
        node *temp = new node(data);
        size++;
        if (head == NULL) {
            head = temp;
            head->next = NULL;
            return;
        }
        temp->next = head;
        head = temp;
        return;
    }

    void insertAtTail(int data) {
        node *temp = new node(data);
        size++;
        if (head == NULL) {
            head = temp;
            head->next = NULL;
            return;
        }
        node *tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = temp;
        tail = temp;
        return;
    }

    void display() {
        if (head == NULL) {
            cout << "Linked List is Empty" << endl;
            return;
        }

        node *temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void detectCycle() {

        if (head == NULL) {
            cout << "Linked List is Empty" << endl;
            return;
        }

        node *slow = head;
        node *fast = head;
        bool cycleFound = false;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                cout << "Cycle detected" << endl;
                cycleFound = true;
                break;
            }
        }

        if (cycleFound) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            while (fast->next != slow) {
                fast = fast->next;
            }

            fast->next = NULL;
            cout << "Cycle removed" << endl;
            return;
        }

        cout << "cycle not present in this linked list" << endl;
    }
};

int main() {
    LinkedList L;
    int choice, data;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert At Head\n";
        cout << "2. Insert At Tail\n";
        cout << "3. Detect & Remove Cycle\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter data: ";
            cin >> data;
            L.insertAtHead(data);
            break;

        case 2:
            cout << "Enter data: ";
            cin >> data;
            L.insertAtTail(data);
            break;

        case 3:
            L.detectCycle();
            break;

        case 4:
            L.display();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}