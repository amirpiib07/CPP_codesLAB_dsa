#include <iostream>
#include <deque>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(const string& s) {
    if (s.empty()) return true;

    deque<char> dq;

    // push only alphanumeric, convert to lowercase (handles "A man a plan...")
    for (char c : s) {
        if (isalnum(c)) dq.push_back(tolower(c));
    }

    if (dq.empty()) return true;

    while (dq.size() > 1) {
        if (dq.front() != dq.back()) return false;
        dq.pop_front();
        dq.pop_back();
    }
    return true;
}

int main() {
    cout << "=== Palindrome Check Using Deque ===\n";
    cout << "Enter string: ";
    string s;
    //cin.ignore();
    getline(cin, s);

    if (s.empty()) { cout << "Empty string.\n"; return 1; }

    if (isPalindrome(s))
        cout << "\"" << s << "\" is a Palindrome.\n";
    else
        cout << "\"" << s << "\" is NOT a Palindrome.\n";

    return 0;
}