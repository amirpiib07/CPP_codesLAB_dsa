#include <iostream>
#include <queue>
using namespace std;

// For array-based queue: count = rear - front + 1
int countArray(int front, int rear) {
    if (front > rear) return 0;
    return rear - front + 1;
}

// For STL/linked queue: use size() or traverse
int countQueue(queue<int> q) {  // pass by value -- non-destructive
    return (int)q.size();
}

int main() {
    cout << "=== Count Elements in Queue ===\n";

    // --- Demo with array queue ---
    int cap, val;
    cout << "Enter capacity of array queue: ";
    cin >> cap;
    if (cap <= 0) { cout << "Invalid.\n"; return 1; }

    int* arr = new int[cap];
    int front = 0, rear = -1;

    int n;
    cout << "Enter number of elements to enqueue: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        if (rear < cap - 1) arr[++rear] = val;
        else { cout << "Queue full, skipping " << val << ".\n"; }
    }

    cout << "\nArray Queue -- front=" << front << " rear=" << rear << "\n";
    cout << "Count (rear - front + 1) = " << countArray(front, rear) << "\n";

    // --- Demo with STL queue ---
    queue<int> q;
    for (int i = front; i <= rear; i++) q.push(arr[i]);
    cout << "STL Queue size() = " << countQueue(q) << "\n";

    // dequeue a couple and recount
    if (!q.empty()) q.pop();
    if (!q.empty()) q.pop();
    cout << "After 2 dequeues, count = " << countQueue(q) << "\n";

    delete[] arr;
    return 0;
}