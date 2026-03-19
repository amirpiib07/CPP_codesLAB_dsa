#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;
    node *prev;

    node(int data) {
        this->next = NULL;
        this->prev = NULL;
        this->data = data;
    }
};

class DoubleLL {
    node* head = NULL;
    node* tail = NULL;

public:

    void pushFront(int data) {

        node *temp = new node(data);

        if (head == NULL) {
            head = tail = temp;
            return;
        }

        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    void print() {

        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverseList() {

        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        node* oldHead = head;

        node* curr = head;
        node* pre = nullptr;
        node* ford = nullptr;

        while (curr != nullptr) {
            ford = curr->next;
            curr->next = pre;
            curr->prev = ford;
            pre = curr;
            curr = ford;
        }

        head = pre;
        tail = oldHead;
    }
};

int main() {

    DoubleLL l;
    int choice, data;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Push Front\n";
        cout << "2. Print\n";
        cout << "3. Reverse List\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter data: ";
            cin >> data;
            l.pushFront(data);
            break;

        case 2:
            l.print();
            break;

        case 3:
            l.reverseList();
            cout << "List reversed\n";
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