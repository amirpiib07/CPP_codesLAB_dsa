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

/* ===== DISPLAY CIRCULAR LIST ===== */

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

/* ===== SPLIT FUNCTION ===== */

void splitCircular(node* head) {

    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    if (head->next == head) {
        cout << "Only one node. Cannot split.\n";
        return;
    }

    node* slow = head;
    node* fast = head;

    // Find middle using slow-fast
    while (fast->next != head &&
           fast->next->next != head) {

        slow = slow->next;
        fast = fast->next->next;
    }

    node* head1 = head;
    node* head2 = slow->next;

    // Make first half circular
    slow->next = head1;

    // If even number of nodes
    if (fast->next->next == head)
        fast = fast->next;

    // Make second half circular
    fast->next = head2;

    cout << "\nFirst Half:\n";
    display(head1);

    cout << "Second Half:\n";
    display(head2);
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

    cout << "\nOriginal Circular List:\n";
    display(head);

    splitCircular(head);

    return 0;
}