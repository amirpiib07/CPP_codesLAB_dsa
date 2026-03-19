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

/* ===== DELETE EVERY Kth NODE ===== */

int deleteEveryK(node* head, int k) {

    if (head == NULL || k <= 0)
        return -1;

    node* curr = head;
    node* prev = NULL;

    // Find last node to initialize prev
    while (curr->next != head)
        curr = curr->next;

    prev = curr;
    curr = head;

    while (curr->next != curr) {  // more than one node

        // Move k-1 steps
        for (int i = 1; i < k; i++) {
            prev = curr;
            curr = curr->next;
        }

        // Delete k-th node
        prev->next = curr->next;
        node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return curr->data;  // last remaining node
}

/* ===== MAIN ===== */

int main() {

    int n, data, k;

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

    cout << "\nCircular List:\n";
    display(head);

    cout << "\nEnter value of k: ";
    cin >> k;

    int survivor = deleteEveryK(head, k);

    cout << "\nRemaining node:\n" << survivor << endl;

    return 0;
}