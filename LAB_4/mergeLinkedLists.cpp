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
    }

    void display() {
        if (head == NULL) {
            cout << "Empty List\n";
            return;
        }

        node *temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    node *headGroup() {
        return head;
    }
};

node *merge(node *head1, node *head2) {

    node *dummy = new node(-1);
    node *k = dummy;
    node *i = head1;
    node *j = head2;

    while (i != NULL && j != NULL) {
        if (i->data <= j->data) {
            k->next = i;
            i = i->next;
        } else {
            k->next = j;
            j = j->next;
        }
        k = k->next;
    }

    if (i != NULL)
        k->next = i;

    if (j != NULL)
        k->next = j;

    node *result = dummy->next;
    delete dummy;   // Fix memory leak
    return result;
}

void printList(node *ptr) {

    if (ptr == NULL) {
        cout << "Empty List\n";
        return;
    }

    node *curr = ptr;
    while (curr != NULL) {
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << "NULL\n";
}

int main() {

    LinkedList L, M;
    int choice, data;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert in List 1\n";
        cout << "2. Insert in List 2\n";
        cout << "3. Display List 1\n";
        cout << "4. Display List 2\n";
        cout << "5. Merge & Display\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter data (sorted order): ";
            cin >> data;
            L.insertAtTail(data);
            break;

        case 2:
            cout << "Enter data (sorted order): ";
            cin >> data;
            M.insertAtTail(data);
            break;

        case 3:
            L.display();
            break;

        case 4:
            M.display();
            break;

        case 5:
            printList(merge(L.headGroup(), M.headGroup()));
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