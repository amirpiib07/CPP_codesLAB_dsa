#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;

    node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoubleLL {

public:
    node* head = NULL;
    node* tail = NULL;

    void pushBack(int data) {

        node* temp = new node(data);

        if (head == NULL) {
            head = tail = temp;
            return;
        }

        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }

    void print() {

        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

/* ===== MERGE FUNCTION ===== */

node* merge(node* head1, node* head2) {

    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    node* dummy = new node(-1);
    node* curr = dummy;

    while (head1 != NULL && head2 != NULL) {

        if (head1->data <= head2->data) {

            curr->next = head1;
            head1->prev = curr;

            head1 = head1->next;
        }
        else {

            curr->next = head2;
            head2->prev = curr;

            head2 = head2->next;
        }

        curr = curr->next;
    }

    // Attach remaining nodes
    if (head1 != NULL) {
        curr->next = head1;
        head1->prev = curr;
    }

    if (head2 != NULL) {
        curr->next = head2;
        head2->prev = curr;
    }

    node* newHead = dummy->next;
    newHead->prev = NULL;

    delete dummy;

    return newHead;
}

/* ===== PRINT FUNCTION FOR MERGED LIST ===== */

void printList(node* head) {

    node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

/* ===== MAIN ===== */

int main() {

    DoubleLL list1, list2;

    int n1, n2, data;

    cout << "Enter number of elements in List 1: ";
    cin >> n1;

    cout << "Enter sorted elements for List 1:\n";
    for (int i = 0; i < n1; i++) {
        cin >> data;
        list1.pushBack(data);
    }

    cout << "\nEnter number of elements in List 2: ";
    cin >> n2;

    cout << "Enter sorted elements for List 2:\n";
    for (int i = 0; i < n2; i++) {
        cin >> data;
        list2.pushBack(data);
    }

    cout << "\nList 1:\n";
    list1.print();

    cout << "List 2:\n";
    list2.print();

    node* mergedHead = merge(list1.head, list2.head);

    cout << "\nMerged Sorted Doubly Linked List:\n";
    printList(mergedHead);

    return 0;
}