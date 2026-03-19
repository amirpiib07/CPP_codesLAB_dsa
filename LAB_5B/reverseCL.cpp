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

/* ===== REVERSE FUNCTION ===== */

node* reverseCircular(node* head) {

    if (head == NULL || head->next == head)
        return head;

    // Step 1: Find last node
    node* last = head;
    while (last->next != head)
        last = last->next;

    // Step 2: Break circle
    last->next = NULL;

    // Step 3: Reverse normal linked list
    node* prev = NULL;
    node* curr = head;
    node* nextNode = NULL;

    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    // Step 4: Make circular again
    head->next = prev;   // old head becomes last
    head = prev;         // new head

    // Move to last node again
    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head;

    return head;
}

/* ===== MAIN ===== */

int main() {

    int n, data;

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size\n";
        return 0;
    }

    node* head = NULL;
    node* tail = NULL;

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++) {

        cin >> data;
        node* temp = new node(data);

        if (head == NULL) {
            head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    // Make circular
    tail->next = head;

    cout << "\nOriginal Circular Linked List:\n";
    display(head);

    head = reverseCircular(head);

    cout << "\nReversed Circular Linked List:\n";
    display(head);

    return 0;
}