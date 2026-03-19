#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

/* ===== DISPLAY FUNCTION ===== */

void display(node* head) {

    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    node* temp = head;

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to " << head->data << ")" << endl;
}

/* ===== INSERT FUNCTION ===== */

node* insertSorted(node* head, int value) {

    node* newNode = new node(value);

    // Case 1: Empty list
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    node* temp = head;

    // Case 2: Insert before head (smallest element)
    if (value <= head->data) {

        // Find last node
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;

        head = newNode;
        return head;
    }

    // Case 3 & 4: Insert in middle or end
    while (temp->next != head &&
           temp->next->data < value) {

        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

/* ===== MAIN ===== */

int main() {

    int n, data, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    node* head = NULL;
    node* tail = NULL;

    if (n > 0) {

        cout << "Enter elements in sorted order:\n";

        for (int i = 0; i < n; i++) {

            cin >> data;
            node* temp = new node(data);

            if (head == NULL) {
                head = tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }
        }

        // Make circular
        tail->next = head;
    }

    cout << "\nOriginal Circular List:\n";
    display(head);

    cout << "\nEnter value to insert: ";
    cin >> value;

    head = insertSorted(head, value);

    cout << "\nAfter insertion:\n";
    display(head);

    return 0;
}