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
    void insertionByPosition(int position, int data) {
        if (position < 0 || position > size) {
            cout << "Position out of bounds" << endl;
            return;
        }

        node *temp = new node(data);
        size++;

        if (head == NULL) {
            head = temp;
            return;
        }

        if (position == 0) {
            temp->next = head;
            head = temp;
            return;
        }

        node *check = head;
        for (int i = 1; i < position; i++) {
            check = check->next;
        }

        temp->next = check->next;
        check->next = temp;
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

    void deleteByPosition(int position) {
        if (position < 0 || position > size - 1) {
            cout << "Position out of bounds" << endl;
            return;
        }

        node *temp = head;

        if (position == 0) {
            node *del = head;
            head = head->next;
            delete del;
            size--;
            return;
        }

        for (int i = 1; i < position; i++) {
            temp = temp->next;
        }

        node *del = temp->next;
        temp->next = temp->next->next;
        delete del;
        size--;
        return;
    }

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
};

int main() {
    LinkedList L;
    int choice, data, position;

    do {
        cout << "\n===== LINKED LIST MENU =====\n";
        cout << "1. Insert At Head\n";
        cout << "2. Insert By Position\n";
        cout << "3. Delete By Position\n";
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
            cout << "Enter position: ";
            cin >> position;
            cout << "Enter data: ";
            cin >> data;
            L.insertionByPosition(position, data);
            break;

        case 3:
            cout << "Enter position to delete: ";
            cin >> position;
            L.deleteByPosition(position);
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