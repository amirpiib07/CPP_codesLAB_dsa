#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedQueue {
    Node* front;
    Node* rear;
    int count;

public:
    LinkedQueue() : front(nullptr), rear(nullptr), count(0) {}

    ~LinkedQueue() { while (front) dequeue(); }

    bool isEmpty() { return front == nullptr; }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear) rear->next = newNode;
        else front = newNode;       // first element
        rear = newNode;
        count++;
        cout << val << " enqueued.\n";
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue Underflow.\n"; return; }
        Node* temp = front;
        cout << "Dequeued: " << temp->data << "\n";
        front = front->next;
        if (!front) rear = nullptr;  // queue became empty
        delete temp;
        count--;
    }

    void frontVal() {
        if (isEmpty()) { cout << "Queue is empty.\n"; return; }
        cout << "Front = " << front->data << "\n";
    }

    void display() {
        if (isEmpty()) { cout << "Queue is empty.\n"; return; }
        cout << "Queue (front to rear): ";
        Node* cur = front;
        while (cur) { cout << cur->data << " "; cur = cur->next; }
        cout << "\n";
    }

    void size() { cout << "Size = " << count << "\n"; }
};

int main() {
    LinkedQueue q;
    int choice, val;
    cout << "=== Queue Using Linked List ===\n";
    cout << "1.Enqueue 2.Dequeue 3.Front 4.Display 5.Size 6.Exit\n";

    while (true) {
        cout << "\nChoice: ";
        cin >> choice;
        if      (choice == 1) { cout << "Value: "; cin >> val; q.enqueue(val); }
        else if (choice == 2) { q.dequeue(); }
        else if (choice == 3) { q.frontVal(); }
        else if (choice == 4) { q.display(); }
        else if (choice == 5) { q.size(); }
        else if (choice == 6) { break; }
        else { cout << "Invalid choice.\n"; }
    }
    return 0;
}