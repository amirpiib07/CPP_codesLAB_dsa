#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int largestRectangle(vector<int>& hist) {
    int n = hist.size();
    stack<int> stk;
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        int currHeight = (i == n) ? 0 : hist[i]; // sentinel at end

        while (!stk.empty() && hist[stk.top()] > currHeight) {
            int height = hist[stk.top()];
            stk.pop();
            int width = stk.empty() ? i : (i - stk.top() - 1);
            maxArea = max(maxArea, height * width);
        }
        stk.push(i);
    }
    return maxArea;
}

int main() {
    int n;
    cout << "=== Largest Rectangle in Histogram ===\n";
    cout << "Enter number of bars: ";
    cin >> n;

    if (n <= 0) { cout << "Invalid input.\n"; return 1; }

    vector<int> hist(n);
    cout << "Enter bar heights: ";
    for (int i = 0; i < n; i++) {
        cin >> hist[i];
        if (hist[i] < 0) { cout << "Heights must be non-negative.\n"; return 1; }
    }

    cout << "\nLargest Rectangular Area = " << largestRectangle(hist) << "\n";
    return 0;
}