#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <cmath>
using namespace std;

#define MAX 200

class DoubleStack {
    double arr[MAX];
    int top;
public:
    DoubleStack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull()  { return top == MAX - 1; }

    void push(double v) {
        if (isFull()) { cout << "Stack overflow!\n"; return; }
        arr[++top] = v;
    }

    double pop() {
        if (isEmpty()) { cout << "Stack underflow!\n"; return 0; }
        return arr[top--];
    }

    double peek() { return isEmpty() ? 0 : arr[top]; }
};

bool isOperator(const string& tok) {
    return tok == "+" || tok == "-" || tok == "*" || tok == "/" || tok == "^";
}

int main() {
    cout << "=== Experiment 5: Evaluate Postfix Expression ===\n";
    cout << "Enter postfix expression (tokens separated by spaces):\n";
    cout << "Example: 8 2 / 3 - \n";
    cout << "Expression: ";

    string line;
    //cin.ignore();
    getline(cin, line);

    if (line.empty()) {
        cout << "Empty expression.\n";
        return 0;
    }

    DoubleStack s;
    istringstream iss(line);
    string token;
    bool valid = true;

    while (iss >> token) {
        // Check if token is a number (handles negatives like -3)
        bool isNum = true;
        for (int i = 0; i < (int)token.size(); i++) {
            if (i == 0 && token[i] == '-' && token.size() > 1) continue;
            if (!isdigit(token[i]) && token[i] != '.') { isNum = false; break; }
        }

        if (isNum) {
            s.push(stod(token));
        }
        else if (isOperator(token)) {
            if (s.isEmpty()) {
                cout << "[Error] Not enough operands for operator '" << token << "'\n";
                valid = false;
                break;
            }
            double b = s.pop();
            if (s.isEmpty()) {
                cout << "[Error] Not enough operands for operator '" << token << "'\n";
                valid = false;
                break;
            }
            double a = s.pop();

            if (token == "/" && b == 0) {
                cout << "[Error] Division by zero!\n";
                valid = false;
                break;
            }

            double result;
            if      (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else if (token == "/") result = a / b;
            else                   result = pow(a, b); // ^

            s.push(result);
        }
        else {
            cout << "[Error] Invalid token '" << token << "'\n";
            valid = false;
            break;
        }
    }

    if (valid) {
        if (s.isEmpty()) {
            cout << "[Error] Empty expression or no result.\n";
        } else {
            double ans = s.pop();
            if (!s.isEmpty()) {
                cout << "[Error] Invalid postfix expression (too many operands).\n";
            } else {
                cout << "Result: " << ans << "\n";
            }
        }
    }

    return 0;
}