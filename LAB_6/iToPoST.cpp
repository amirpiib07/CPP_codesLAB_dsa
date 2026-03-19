#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define MAX 200

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

int precedence(char op) {
    if (op == '^')           return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool isRightAssociative(char op) {
    return op == '^';
}

string infixToPostfix(const string& infix) {
    CharStack s;
    string postfix = "";

    for (int i = 0; i < (int)infix.size(); i++) {
        char c = infix[i];

        if (c == ' ') continue; // skip spaces

        // Multi-digit operand or variable: push directly
        if (isalnum(c)) {
            postfix += c;
            // Handle multi-digit numbers
            while (i + 1 < (int)infix.size() && isalnum(infix[i + 1])) {
                postfix += infix[++i];
            }
            postfix += ' '; // space separator for multi-char tokens
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            // Pop until matching '('
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
                postfix += ' ';
            }
            if (s.isEmpty()) {
                cout << "[Error] Mismatched parentheses detected.\n";
                return "";
            }
            s.pop(); // remove '('
        }
        else if (isOperator(c)) {
            while (!s.isEmpty() && s.peek() != '(' &&
                   isOperator(s.peek()) &&
                   (precedence(s.peek()) > precedence(c) ||
                   (precedence(s.peek()) == precedence(c) && !isRightAssociative(c)))) {
                postfix += s.pop();
                postfix += ' ';
            }
            s.push(c);
        }
        else {
            cout << "[Warning] Unknown character '" << c << "' ignored.\n";
        }
    }

    while (!s.isEmpty()) {
        if (s.peek() == '(') {
            cout << "[Error] Mismatched parentheses detected.\n";
            return "";
        }
        postfix += s.pop();
        postfix += ' ';
    }

    return postfix;
}

int main() {
    cout << "=== Experiment 4: Infix to Postfix Conversion ===\n";
    cout << "Supported operators: + - * / ^\n";
    cout << "Operands: single letters (A,B) or digits (1,2,...)\n\n";

    string infix;
    cout << "Enter infix expression: ";
    //cin.ignore();
    getline(cin, infix);

    if (infix.empty()) {
        cout << "Empty expression entered.\n";
        return 0;
    }

    string result = infixToPostfix(infix);

    if (!result.empty()) {
        cout << "Infix   : " << infix  << "\n";
        cout << "Postfix : " << result << "\n";
    }

    return 0;
}