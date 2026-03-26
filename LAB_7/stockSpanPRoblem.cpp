#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> stockSpan(vector<int>& price) {
    int n = price.size();
    vector<int> span(n);
    stack<int> stk; // stores indices

    for (int i = 0; i < n; i++) {
        // pop while top's price <= current price
        while (!stk.empty() && price[stk.top()] <= price[i])
            stk.pop();

        span[i] = stk.empty() ? (i + 1) : (i - stk.top());
        stk.push(i);
    }
    return span;
}

int main() {
    int n;
    cout << "=== Stock Span Problem ===\n";
    cout << "Enter number of days: ";
    cin >> n;

    if (n <= 0) { cout << "Invalid input.\n"; return 1; }

    vector<int> price(n);
    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++) cin >> price[i];

    vector<int> span = stockSpan(price);

    cout << "\nDay  Price  Span\n";
    cout << "---  -----  ----\n";
    for (int i = 0; i < n; i++)
        cout << i+1 << "    " << price[i] << "      " << span[i] << "\n";

    return 0;
}