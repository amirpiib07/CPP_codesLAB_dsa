#include <iostream>
#include <string>
using namespace std;

#define MAX 1000

class CharStack {
    char arr[MAX];
    int top;
public:
    CharStack() { top = -1; }
    bool isEmpty() { return top == -1; }
    void push(char c) { if (top < MAX - 1) arr[++top] = c; }
    char pop()  { return isEmpty() ? '\0' : arr[top--]; }
    char peek() { return isEmpty() ? '\0' : arr[top];   }
};

bool isOpening(char c) { return c == '(' || c == '[' || c == '{'; }
bool isClosing(char c) { return c == ')' || c == ']' || c == '}'; }

bool isMatch(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int main() {
    cout << "=== Experiment 3: Balanced Parentheses ===\n";

    string expr;
    cout << "Enter expression: ";
    //cin.ignore();
    getline(cin, expr);

    // Edge case: empty expression
    if (expr.empty()) {
        cout << "Expression is empty. Trivially balanced.\n";
        return 0;
    }

    CharStack s;
    bool balanced = true;
    int mismatch_pos = -1;

    for (int i = 0; i < (int)expr.size(); i++) {
        char c = expr[i];

        if (isOpening(c)) {
            s.push(c);
        } else if (isClosing(c)) {
            if (s.isEmpty()) {
                balanced = false;
                mismatch_pos = i;
                break;
            }
            char top = s.pop();
            if (!isMatch(top, c)) {
                balanced = false;
                mismatch_pos = i;
                break;
            }
        }
        // all other characters (letters, digits, operators, spaces) are ignored
    }

    // unmatched opening brackets still left in stack
    if (balanced && !s.isEmpty()) {
        balanced = false;
    }

    if (balanced)
        cout << "Result: Balanced\n";
    else if (mismatch_pos != -1)
        cout << "Result: NOT Balanced (mismatch at position " << mismatch_pos << " -> '" << expr[mismatch_pos] << "')\n";
    else
        cout << "Result: NOT Balanced (unmatched opening bracket remains)\n";

    return 0;
}