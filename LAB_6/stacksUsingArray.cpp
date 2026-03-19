#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull()  { return top == MAX - 1; }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << val << "\n";
            return;
        }
        arr[++top] = val;
        cout << val << " pushed.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop.\n";
            return;
        }
        cout << "Popped: " << arr[top--] << "\n";
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element.\n";
            return;
        }
        cout << "Top element: " << arr[top] << "\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

int main() {
    Stack s;
    int choice, val;

    cout << "=== Experiment 1: Stack Using Array ===\n";

    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. isFull\n6. Display\n0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;
            case 2: s.pop();   break;
            case 3: s.peek();  break;
            case 4: cout << (s.isEmpty() ? "Stack IS empty.\n" : "Stack is NOT empty.\n"); break;
            case 5: cout << (s.isFull()  ? "Stack IS full.\n"  : "Stack is NOT full.\n");  break;
            case 6: s.display(); break;
            case 0: cout << "Exiting.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}