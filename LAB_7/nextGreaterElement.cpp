#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> stk; // stores indices

    for (int i = 0; i < n; i++) {
        // pop all indices whose element is less than arr[i]
        while (!stk.empty() && arr[stk.top()] < arr[i]) {
            result[stk.top()] = arr[i];
            stk.pop();
        }
        stk.push(i);
    }
    // remaining indices in stack have no next greater -> result stays -1
    return result;
}

int main() {
    int n;
    cout << "=== Next Greater Element ===\n";
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) { cout << "Invalid size.\n"; return 1; }

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> res = nextGreaterElement(arr);

    cout << "\nElement -> Next Greater\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "  ->  ";
        if (res[i] == -1) cout << "None\n";
        else cout << res[i] << "\n";
    }
    return 0;
}