#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// parse multi-digit numbers from prefix string
// tokens are space-separated
int evaluatePrefix(const string& expr) {
    stack<int> stk;
    int n = expr.size();

    // traverse right to left
    for (int i = n - 1; i >= 0; i--) {
        if (expr[i] == ' ') continue;

        if (isOperator(expr[i])) {
            if (stk.size() < 2) {
                cout << "Invalid expression.\n";
                return INT_MIN;
            }
            int op1 = stk.top(); stk.pop();
            int op2 = stk.top(); stk.pop();

            if      (expr[i] == '+') stk.push(op1 + op2);
            else if (expr[i] == '-') stk.push(op1 - op2);
            else if (expr[i] == '*') stk.push(op1 * op2);
            else {
                if (op2 == 0) { cout << "Division by zero.\n"; return INT_MIN; }
                stk.push(op1 / op2);
            }
        } else if (isdigit(expr[i])) {
            // collect full multi-digit number (digits appear left of current i)
            int j = i;
            while (j >= 0 && isdigit(expr[j])) j--;
            int num = stoi(expr.substr(j + 1, i - j));
            stk.push(num);
            i = j + 1; // skip the digits we already consumed
        } else {
            cout << "Unknown character: " << expr[i] << "\n";
            return INT_MIN;
        }
    }

    if (stk.size() != 1) { cout << "Invalid expression.\n"; return INT_MIN; }
    return stk.top();
}

int main() {
    cout << "=== Prefix Expression Evaluator ===\n";
    cout << "Enter prefix expression (space-separated tokens, e.g. - + 7 * 4 5 + 2 0):\n";
    string expr;
    //cin.ignore();
    getline(cin, expr);

    if (expr.empty()) { cout << "Empty expression.\n"; return 1; }

    int result = evaluatePrefix(expr);
    if (result != INT_MIN)
        cout << "Result = " << result << "\n";

    return 0;
}