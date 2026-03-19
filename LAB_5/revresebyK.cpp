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
    node* head = NULL;
    node* tail = NULL;
    int size = 0;

public:

    void pushBack(int data) {

        node* temp = new node(data);
        size++;

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

    void rotate(int k) {

        if (head == NULL || k == 0 || size == 0)
            return;

        k = k % size;

        if (k == 0)
            return;

        node* temp = head;

        // Move to k-th node
        for (int i = 1; i < k; i++) {
            temp = temp->next;
        }

        node* newHead = temp->next;

        // Break link
        temp->next = NULL;
        newHead->prev = NULL;

        // Connect old tail to old head
        tail->next = head;
        head->prev = tail;

        // Update head and tail
        head = newHead;
        tail = temp;
    }
};

int main() {

    DoubleLL l;

    int n, data, k;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> data;
        l.pushBack(data);
    }

    cout << "\nOriginal List:\n";
    l.print();

    cout << "\nEnter value of k: ";
    cin >> k;

    l.rotate(k);

    cout << "\nList after rotation:\n";
    l.print();

    return 0;
}