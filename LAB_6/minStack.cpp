#include <iostream>
using namespace std;

#define MAX 100

class MinStack {
    int main_arr[MAX]; // main stack
    int min_arr[MAX];  // auxiliary min stack
    int top;
    int min_top;

public:
    MinStack() { top = -1; min_top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull()  { return top == MAX - 1; }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }
        main_arr[++top] = val;
        cout << val << " pushed.\n";

        // Push to min stack if empty or val <= current min
        if (min_top == -1 || val <= min_arr[min_top])
            min_arr[++min_top] = val;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop.\n";
            return;
        }
        int popped = main_arr[top--];
        cout << "Popped: " << popped << "\n";

        // If popped value was the current minimum, remove from min stack too
        if (popped == min_arr[min_top])
            min_top--;
    }

    void getMin() {
        if (isEmpty()) {
            cout << "Stack is empty. No minimum.\n";
            return;
        }
        cout << "Current Minimum: " << min_arr[min_top] << "\n";
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Top: " << main_arr[top] << "\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--)
            cout << main_arr[i] << " ";
        cout << "\n";
        cout << "Min Stack (top to bottom): ";
        for (int i = min_top; i >= 0; i--)
            cout << min_arr[i] << " ";
        cout << "\n";
    }
};

int main() {
    MinStack ms;
    int choice, val;

    cout << "=== Experiment 6: Stack with O(1) Minimum Retrieval ===\n";

    do {
        cout << "\n1. Push\n2. Pop\n3. Get Minimum\n4. Peek\n5. Display\n0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                ms.push(val);
                break;
            case 2: ms.pop();     break;
            case 3: ms.getMin();  break;
            case 4: ms.peek();    break;
            case 5: ms.display(); break;
            case 0: cout << "Exiting.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}