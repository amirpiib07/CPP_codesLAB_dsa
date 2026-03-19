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
public:
    node *head = NULL;
    int size = 0;

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
        return;
    }

    void display() {
        if (head == NULL) {
            cout << "Empty List" << endl;
            return;
        }

        node *temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void reverse(int k) {

        if (head == NULL) {
            cout << "Empty" << endl;
            return;
        }

        if (k <= 1) return;

        node *dummy = new node(-1);
        dummy->next = head;
        node *prevGroupTail = dummy;
        node *curr = head;

        int count = 0;
        while (curr != NULL) {
            curr = curr->next;
            count++;
        }

        curr = head;

        while (count >= k) {

            node *groupHead = curr;
            node *prev = NULL;
            node *ford = NULL;

            for (int i = 0; i < k; i++) {
                ford = curr->next;
                curr->next = prev;
                prev = curr;
                curr = ford;
            }

            prevGroupTail->next = prev;
            groupHead->next = curr;

            prevGroupTail = groupHead;
            count -= k;
        }

        head = dummy->next;
        delete dummy;   // fix memory leak
    }
};

int main() {
    LinkedList L;
    int choice, data, k;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert At Head\n";
        cout << "2. Insert At Tail\n";
        cout << "3. Reverse in K Group\n";
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
            cout << "Enter k: ";
            cin >> k;
            L.reverse(k);
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