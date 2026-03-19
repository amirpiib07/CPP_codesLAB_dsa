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
    node *tail = NULL;
    int size = 0;

public:
    void insertAtTail(int data) {
        node *temp = new node(data);
        size++;
        if (tail == NULL) {
            tail = head = temp;
            head->next = NULL;
            tail->next = NULL;
            return;
        }
        tail->next = temp;
        tail = temp;
        return;
    }

    void display() {
        node *temp = head;
        if (head == NULL) {
            cout << "The list is empty" << endl;
            return;
        }
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList L;
    int choice, data;

    do {
        cout << "\n===== LINKED LIST MENU =====\n";
        cout << "1. Insert At Tail\n";
        cout << "2. Display\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter data: ";
                cin >> data;
                L.insertAtTail(data);
                break;

            case 2:
                L.display();
                break;

            case 3:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 3);

    return 0;
}