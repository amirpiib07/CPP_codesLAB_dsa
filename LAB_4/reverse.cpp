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
            return;
        }
        node *tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = temp;
        return;
    }

    void display() {
        if (head == NULL) {
            cout << "The list is empty" << endl;
            return;
        }

        node *temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void reverseList() {
        if (head == NULL) {
            cout << "The list is empty" << endl;
            return;
        }

        node *curr = head;
        node *prev = NULL;
        node *ford = NULL;

        while (curr != NULL) {
            ford = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ford;
        }

        head = prev;
        return;
    }
};

int main() {

    LinkedList L;
    int choice, data;

    do {
        cout << "\n===== LINKED LIST MENU =====\n";
        cout << "1. Insert At Head\n";
        cout << "2. Insert At Tail\n";
        cout << "3. Display\n";
        cout << "4. Reverse List\n";
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
            L.display();
            break;

        case 4:
            L.reverseList();
            cout << "List reversed successfully\n";
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