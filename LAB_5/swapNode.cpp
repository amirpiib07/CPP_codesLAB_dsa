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

    void swapNodes(int pos1, int pos2) {

        if (pos1 == pos2) return;

        if (pos1 < 1 || pos2 < 1 || pos1 > size || pos2 > size) {
            cout << "Invalid positions\n";
            return;
        }

        if (pos1 > pos2)
            swap(pos1, pos2);

        node* node1 = head;
        node* node2 = head;

        for (int i = 1; i < pos1; i++)
            node1 = node1->next;

        for (int i = 1; i < pos2; i++)
            node2 = node2->next;

        // If adjacent nodes
        if (node1->next == node2) {

            node* prev1 = node1->prev;
            node* next2 = node2->next;

            if (prev1) prev1->next = node2;
            node2->prev = prev1;

            node2->next = node1;
            node1->prev = node2;

            node1->next = next2;
            if (next2) next2->prev = node1;

        } else {

            node* prev1 = node1->prev;
            node* next1 = node1->next;

            node* prev2 = node2->prev;
            node* next2 = node2->next;

            if (prev1) prev1->next = node2;
            if (next1) next1->prev = node2;

            if (prev2) prev2->next = node1;
            if (next2) next2->prev = node1;

            node1->next = next2;
            node1->prev = prev2;

            node2->next = next1;
            node2->prev = prev1;
        }

        // Update head
        if (pos1 == 1)
            head = node2;
        else if (pos2 == 1)
            head = node1;

        // Update tail
        if (pos1 == size)
            tail = node2;
        else if (pos2 == size)
            tail = node1;
    }
};

int main() {

    DoubleLL l;

    int n, data, pos1, pos2;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> data;
        l.pushBack(data);
    }

    cout << "\nOriginal List:\n";
    l.print();

    cout << "\nEnter two positions to swap: ";
    cin >> pos1 >> pos2;

    l.swapNodes(pos1, pos2);

    cout << "\nList after swapping nodes:\n";
    l.print();

    return 0;
}