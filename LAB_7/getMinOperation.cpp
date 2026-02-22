#include<iostream>
#include <stack>
using namespace std;

class minStack {
    stack<int> st;
    stack<int> minst;

public:
    void push(int data) {
        st.push(data);
        if (minst.empty() || data < minst.top()) minst.push(data);
    }

    void pop() {
        if (st.empty()) return;

        if (st.top() == minst.top()) minst.pop();
        st.pop();
    }

    int peek() {
        if (st.empty()) return -1;
        return st.top();
    }

    int getMin() {
        if (minst.empty()) return -1;
        return minst.top();
    }
};

int main() {
    minStack st;
    st.push(10);
    st.push(20);
    st.push(-1);
    cout << st.peek() << endl;
    cout << st.getMin() << endl;
    st.pop();
    cout << st.getMin() << endl;

    return 0;
}
