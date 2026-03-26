#include <iostream>
using namespace std;

class LinearQueue {
    int* arr;
    int front, rear, capacity;

public:
    LinearQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }

    ~LinearQueue() { delete[] arr; }

    bool isEmpty() { return front > rear; }
    bool isFull()  { return rear == capacity - 1; }

    void enqueue(int val) {
        if (isFull()) { cout << "Queue Overflow. Cannot enqueue " << val << ".\n"; return; }
        arr[++rear] = val;
        cout << val << " enqueued.\n";
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue Underflow. Nothing to dequeue.\n"; return; }
        cout << "Dequeued: " << arr[front++] << "\n";
    }

    void frontVal() {
        if (isEmpty()) { cout << "Queue is empty.\n"; return; }
        cout << "Front = " << arr[front] << "\n";
    }

    void display() {
        if (isEmpty()) { cout << "Queue is empty.\n"; return; }
        cout << "Queue (front to rear): ";
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << "\n";
    }

    int size() { return isEmpty() ? 0 : rear - front + 1; }
};

int main() {
    int cap;
    cout << "=== Linear Queue Using Array ===\n";
    cout << "Enter queue capacity: ";
    cin >> cap;
    if (cap <= 0) { cout << "Invalid capacity.\n"; return 1; }

    LinearQueue q(cap);
    int choice, val;
    cout << "1.Enqueue 2.Dequeue 3.Front 4.Display 5.Size 6.Exit\n";

    while (true) {
        cout << "\nChoice: ";
        cin >> choice;
        if      (choice == 1) { cout << "Value: "; cin >> val; q.enqueue(val); }
        else if (choice == 2) { q.dequeue(); }
        else if (choice == 3) { q.frontVal(); }
        else if (choice == 4) { q.display(); }
        else if (choice == 5) { cout << "Size = " << q.size() << "\n"; }
        else if (choice == 6) { break; }
        else { cout << "Invalid choice.\n"; }
    }
    return 0;
}