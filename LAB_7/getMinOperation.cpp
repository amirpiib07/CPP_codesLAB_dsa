#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack {
    stack<int> main_stk;
    stack<int> min_stk;

public:
    void push(int val) {
        main_stk.push(val);
        if (min_stk.empty() || val <= min_stk.top())
            min_stk.push(val);
        else
            min_stk.push(min_stk.top()); // carry forward current min
    }

    void pop() {
        if (main_stk.empty()) { cout << "Stack underflow\n"; return; }
        main_stk.pop();
        min_stk.pop();
    }

    int peek() {
        if (main_stk.empty()) { cout << "Stack is empty\n"; return INT_MIN; }
        return main_stk.top();
    }

    int getMin() {
        if (min_stk.empty()) { cout << "Stack is empty\n"; return INT_MIN; }
        return min_stk.top();
    }

    bool isEmpty() { return main_stk.empty(); }
};

int main() {
    MinStack ms;
    int choice, val;

    cout << "=== MinStack Operations ===\n";
    cout << "1. Push  2. Pop  3. Peek  4. GetMin  5. Exit\n";

    while (true) {
        cout << "\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            ms.push(val);
            cout << val << " pushed. Current min = " << ms.getMin() << "\n";
        } else if (choice == 2) {
            if (ms.isEmpty()) { cout << "Stack is empty.\n"; continue; }
            cout << "Popped: " << ms.peek() << "\n";
            ms.pop();
            if (!ms.isEmpty())
                cout << "Current min = " << ms.getMin() << "\n";
            else
                cout << "Stack is now empty.\n";
        } else if (choice == 3) {
            int top = ms.peek();
            if (top != INT_MIN) cout << "Top = " << top << "\n";
        } else if (choice == 4) {
            int m = ms.getMin();
            if (m != INT_MIN) cout << "Min = " << m << "\n";
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}