#include <iostream>
using namespace std;

class CircularQueue {
    int* arr;
    int front, rear, capacity, count;

public:
    CircularQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~CircularQueue() { delete[] arr; }

    bool isEmpty() { return count == 0; }
    bool isFull()  { return count == capacity; }

    void enqueue(int val) {
        if (isFull()) { cout << "Queue Overflow. Cannot enqueue " << val << ".\n"; return; }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        count++;
        cout << val << " enqueued.\n";
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue Underflow.\n"; return; }
        cout << "Dequeued: " << arr[front] << "\n";
        front = (front + 1) % capacity;
        count--;
    }

    void frontVal() {
        if (isEmpty()) { cout << "Queue is empty.\n"; return; }
        cout << "Front = " << arr[front] << "\n";
    }

    void display() {
        if (isEmpty()) { cout << "Queue is empty.\n"; return; }
        cout << "Queue (front to rear): ";
        for (int i = 0; i < count; i++)
            cout << arr[(front + i) % capacity] << " ";
        cout << "\n";
    }

    void size() { cout << "Size = " << count << "/" << capacity << "\n"; }
};

int main() {
    int cap;
    cout << "=== Circular Queue ===\n";
    cout << "Enter queue capacity: ";
    cin >> cap;
    if (cap <= 0) { cout << "Invalid capacity.\n"; return 1; }

    CircularQueue q(cap);
    int choice, val;
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