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

/* ===== CHECK SORTED FUNCTION ===== */

bool isSorted(node* head) {

    if (head == NULL) {
        cout << "List is empty\n";
        return false;
    }

    if (head->next == head)
        return true;   // single node always sorted

    node* temp = head;

    do {

        if (temp->next != head &&
            temp->data > temp->next->data) {
            return false;
            }

        temp = temp->next;

    } while (temp != head);

    return true;
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

    cout << "\nCircular List:\n";
    display(head);

    if (isSorted(head))
        cout << "\nThe circular linked list is SORTED.\n";
    else
        cout << "\nThe circular linked list is NOT sorted.\n";

    return 0;
}