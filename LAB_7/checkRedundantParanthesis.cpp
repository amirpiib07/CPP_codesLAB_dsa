#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool hasRedundantParentheses(const string& expr) {
    stack<char> stk;

    for (char c : expr) {
        if (c == '(' || isOperator(c) || isalpha(c)) {
            stk.push(c);
        } else if (c == ')') {
            bool hasOp = false;

            // pop until matching '('
            while (!stk.empty() && stk.top() != '(') {
                if (isOperator(stk.top())) hasOp = true;
                stk.pop();
            }

            if (stk.empty()) {
                cout << "Unmatched ')' found.\n";
                return false;
            }
            stk.pop(); // pop '('

            if (!hasOp) return true; // redundant: no operator inside ()
        }
    }

    // check for unmatched '('
    while (!stk.empty()) {
        if (stk.top() == '(') {
            cout << "Unmatched '(' found.\n";
            return false;
        }
        stk.pop();
    }

    return false;
}

int main() {
    cout << "=== Redundant Parentheses Checker ===\n";
    cout << "Enter expression: ";
    string expr;
    cin >> expr;

    if (expr.empty()) { cout << "Empty expression.\n"; return 1; }

    bool result = hasRedundantParentheses(expr);
    if (result)
        cout << "Redundant parentheses PRESENT.\n";
    else
        cout << "No redundant parentheses.\n";

    return 0;
}