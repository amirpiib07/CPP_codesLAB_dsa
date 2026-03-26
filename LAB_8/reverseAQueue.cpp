#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// --- Approach 1: Using explicit stack ---
void reverseWithStack(queue<int>& q) {
    stack<int> stk;
    while (!q.empty()) { stk.push(q.front()); q.pop(); }
    while (!stk.empty()) { q.push(stk.top()); stk.pop(); }
}

// --- Approach 2: Recursive (uses call stack) ---
void reverseRecursive(queue<int>& q) {
    if (q.empty()) return;
    int front = q.front();
    q.pop();
    reverseRecursive(q);
    q.push(front);
}

void display(queue<int> q) {  // pass by value to avoid modifying original
    cout << "Queue: ";
    while (!q.empty()) { cout << q.front() << " "; q.pop(); }
    cout << "\n";
}

int main() {
    int n, val;
    cout << "=== Reverse a Queue ===\n";
    cout << "Enter number of elements: ";
    cin >> n;
    if (n <= 0) { cout << "Invalid input.\n"; return 1; }

    queue<int> q;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) { cin >> val; q.push(val); }

    cout << "\nOriginal  -> "; display(q);

    int method;
    cout << "Choose method: 1.Stack  2.Recursive: ";
    cin >> method;

    if (method == 1) reverseWithStack(q);
    else if (method == 2) reverseRecursive(q);
    else { cout << "Invalid choice.\n"; return 1; }

    cout << "Reversed  -> "; display(q);
    return 0;
}