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
    }

    void moveLastNodeToFront() {
        if (head == NULL) {
            cout << "The list is empty" << endl;
            return;
        }

        if (head->next == NULL) {
            return;
        }

        node *temp = head;
        node *prev = NULL;

        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        temp->next = head;
        head = temp;
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
        cout << "5. Move Last Node To Front\n";
        cout << "6. Exit\n";
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
            cout << "List Reversed\n";
            break;

        case 5:
            L.moveLastNodeToFront();
            cout << "Last node moved to front\n";
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 6);

    return 0;
}