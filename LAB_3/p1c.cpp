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

    void deleteByData(int data) {
        if (head == NULL) {
            cout << "The list is empty" << endl;
            return;
        }

        node *temp = head;
        node *check = NULL;

        if (head->data == data) {
            node *del = head;
            head = head->next;
            delete del;
            size--;
            return;
        }

        while (temp != NULL && temp->data != data) {
            check = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "data not found in the linked list" << endl;
            return;
        }

        check->next = temp->next;
        delete temp;
        size--;
    }

    void deleteByPosition(int position) {
        if (position < 0 || position > size - 1) {
            cout << "Position out of bounds" << endl;
            return;
        }

        node *temp = head;

        if (position == 0) {
            head = head->next;
            delete temp;
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
    }

    void searchForValue(int data) {
        node *temp = head;
        while (temp != NULL) {
            if (temp->data == data) {
                cout << data << " data found!" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << data << " data not found!" << endl;
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

    void detectCycle() {
        node *slow = head;
        node *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                cout << "Cycle detected" << endl;
                return;
            }
        }
        cout << "cycle not present in this linked list" << endl;
    }
};

int main() {
    LinkedList L;
    int choice, data, position;

    do {
        cout << "\n===== LINKED LIST MENU =====\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Delete by Data\n";
        cout << "4. Delete by Position\n";
        cout << "5. Search Value\n";
        cout << "6. Reverse List\n";
        cout << "7. Detect Cycle\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
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
            cout << "Enter data to delete: ";
            cin >> data;
            L.deleteByData(data);
            break;

        case 4:
            cout << "Enter position to delete: ";
            cin >> position;
            L.deleteByPosition(position);
            break;

        case 5:
            cout << "Enter value to search: ";
            cin >> data;
            L.searchForValue(data);
            break;

        case 6:
            L.reverseList();
            cout << "List reversed\n";
            break;

        case 7:
            L.detectCycle();
            break;

        case 8:
            L.display();
            break;

        case 9:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 9);

    return 0;
}