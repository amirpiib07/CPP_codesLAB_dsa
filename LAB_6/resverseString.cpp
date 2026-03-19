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
    bool isFull()  { return top == MAX - 1; }

    void push(char c) {
        if (isFull()) { cout << "Stack full!\n"; return; }
        arr[++top] = c;
    }

    char pop() {
        if (isEmpty()) return '\0';
        return arr[top--];
    }
};

int main() {
    cout << "=== Experiment 2: Reverse a String Using Stack ===\n";

    string input;
    cout << "Enter a string: ";
    cin >> input;

    // Edge case: empty string
    if (input.empty()) {
        cout << "Input string is empty. Nothing to reverse.\n";
        return 0;
    }

    // Edge case: string too long
    if ((int)input.size() >= MAX) {
        cout << "String too long (max " << MAX - 1 << " chars).\n";
        return 0;
    }

    CharStack s;

    for (char c : input)
        s.push(c);

    string reversed = "";
    while (!s.isEmpty())
        reversed += s.pop();

    cout << "Original : " << input    << "\n";
    cout << "Reversed : " << reversed << "\n";

    return 0;
}
