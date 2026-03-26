#include <iostream>
#include <queue>
#include <climits>
using namespace std;

pair<int,int> findMaxMin(queue<int>& q) {
    if (q.empty()) return {INT_MIN, INT_MAX};

    int maxVal = INT_MIN, minVal = INT_MAX;
    int sz = q.size();

    // traverse without destroying: dequeue then re-enqueue
    for (int i = 0; i < sz; i++) {
        int cur = q.front(); q.pop();
        maxVal = max(maxVal, cur);
        minVal = min(minVal, cur);
        q.push(cur);  // restore
    }
    return {maxVal, minVal};
}

void display(queue<int> q) {
    cout << "Queue: ";
    while (!q.empty()) { cout << q.front() << " "; q.pop(); }
    cout << "\n";
}

int main() {
    int n, val;
    cout << "=== Max and Min in Queue ===\n";
    cout << "Enter number of elements: ";
    cin >> n;
    if (n <= 0) { cout << "Invalid input.\n"; return 1; }

    queue<int> q;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) { cin >> val; q.push(val); }

    display(q);

    auto [maxVal, minVal] = findMaxMin(q);
    cout << "Max = " << maxVal << "\n";
    cout << "Min = " << minVal << "\n";

    cout << "\nQueue after operation (order preserved): ";
    display(q);
    return 0;
}