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
    void delteNthNodeFromEnd(int position) {
        if (head == NULL) {
            cout << "Linked List is Empty" << endl;
            return;
        }

        if (position > size || position <= 0) {
            cout << "invalid node" << endl;
            return;
        }

        // Delete head case
        if (position == size) {
            node *del = head;
            head = head->next;
            delete del;
            size--;
            if (head == NULL) {
                cout << "Linked List is now become Empty" << endl;
            }
            return;
        }

        node *slow = head;
        node *fast = head;

        for (int i = 0; i < position; i++) {
            fast = fast->next;
        }

        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        node *del = slow->next;
        slow->next = slow->next->next;
        delete del;
        size--;
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
        cout << "\n===== MENU =====\n";
        cout << "1. Insert At Head\n";
        cout << "2. Delete Nth Node From End\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter data: ";
            cin >> data;
            L.insertAtHead(data);
            break;

        case 2:
            cout << "Enter position from end: ";
            cin >> position;
            L.delteNthNodeFromEnd(position);
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