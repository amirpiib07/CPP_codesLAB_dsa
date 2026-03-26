#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string removeAdjacentDuplicates(const string& s) {
    if (s.empty()) return "";
    stack<char> stk;

    for (char c : s) {
        if (!stk.empty() && stk.top() == c)
            stk.pop();
        else
            stk.push(c);
    }

    // build result from stack (stack is bottom-to-top, so reverse)
    string result = "";
    while (!stk.empty()) {
        result += stk.top();
        stk.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    cout << "=== Remove Adjacent Duplicates ===\n";
    cout << "Enter string: ";
    string s;
    cin >> s;

    if (s.empty()) { cout << "Empty string.\n"; return 1; }

    string result = removeAdjacentDuplicates(s);
    if (result.empty())
        cout << "Result: (empty string - all characters cancelled)\n";
    else
        cout << "Result: " << result << "\n";

    return 0;
}