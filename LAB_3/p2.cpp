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
    void insertFront(int data) {
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

    void undo() {
        if (head == NULL) {
            cout << "linked list is empty" << endl;
            return;
        }

        node *del = head;
        head = head->next;
        delete del;
        size--;

        if (head == NULL) {
            cout << "linked list is now become empty" << endl;
        }
        return;
    }

    void display() {
        if (head == NULL) {
            cout << "linked list is empty" << endl;
            return;
        }

        node *temp = head;
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
        cout << "\n===== MENU =====\n";
        cout << "1. Insert Front\n";
        cout << "2. Undo (Delete Front)\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter data: ";
                cin >> data;
                L.insertFront(data);
                break;

            case 2:
                L.undo();
                break;

            case 3:
                L.display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}