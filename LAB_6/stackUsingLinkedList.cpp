#include <iostream>
using namespace std;

// ── Node structure ──────────────────────────────────────────────
struct Node {
    int  data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// ── Stack class ─────────────────────────────────────────────────
class Stack {
    Node* top;
    int   size;

public:
    Stack() : top(nullptr), size(0) {}

    // Destructor: free all nodes when program ends
    ~Stack() {
        while (!isEmpty()) pop();
    }

    bool isEmpty() {
        return top == nullptr;
    }

    // Insert node at the beginning  O(1)
    void push(int val) {
        Node* newNode = new(nothrow) Node(val);
        if (newNode == nullptr) {
            // new returned nullptr -> heap exhausted
            cout << "Memory allocation failed! Cannot push " << val << ".\n";
            return;
        }
        newNode->next = top;
        top = newNode;
        size++;
        cout << val << " pushed. (Stack size: " << size << ")\n";
    }

    // Delete node from the beginning  O(1)
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop.\n";
            return;
        }
        Node* temp = top;
        cout << "Popped: " << temp->data << "\n";
        top = top->next;
        delete temp;
        size--;
    }

    // Return top element without removing  O(1)
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element.\n";
            return;
        }
        cout << "Top element: " << top->data << "\n";
    }

    // Display all elements top -> bottom
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack (top -> bottom): ";
        Node* curr = top;
        while (curr != nullptr) {
            cout << curr->data;
            if (curr->next) cout << " -> ";
            curr = curr->next;
        }
        cout << "\n";
        cout << "Total elements: " << size << "\n";
    }

    int getSize() { return size; }
};

// ── Main with menu ───────────────────────────────────────────────
int main() {
    Stack s;
    int choice, val;

    cout << "=== Stack Using Linked List ===\n";

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. isEmpty\n";
        cout << "5. Display\n";
        cout << "6. Size\n";
        cout << "0. Exit\n";
        cout << "Choice: ";

        // Handle non-integer input
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter integer to push: ";
                if (!(cin >> val)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid value. Enter an integer.\n";
                    break;
                }
                s.push(val);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;

            case 4:
                cout << (s.isEmpty() ? "Stack IS empty.\n" : "Stack is NOT empty.\n");
                break;

            case 5:
                s.display();
                break;

            case 6:
                cout << "Current size: " << s.getSize() << "\n";
                break;

            case 0:
                cout << "Exiting. All nodes freed.\n";
                break;

            default:
                cout << "Invalid choice. Enter 0-6.\n";
        }

    } while (choice != 0);

    return 0;
}
