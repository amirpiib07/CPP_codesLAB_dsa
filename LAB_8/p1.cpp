#include <iostream>
using namespace std;

class Stack {
    int *array;
    int f;
    int r;
    int size;

public:
    Stack(int capacity) {
        array = new int[capacity];
        this->f = 0;
        this->r = 0;
    }

    ~Stack() {
        delete[] array;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        array[r++] = x;
        return;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        f++;
    }

    int front() {
        if (r == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return array[f];
    }

    bool isEmpty() {
        return r == 0;
    }

    bool isFull() {
        return r == size;
    }

    int getSize() {
        return r - f ;
    }
};

int main() {
    int n;
    cout << "Enter the capacity of the stack:";
    cin >> n;
    Stack s(n);
    int choice;

    do {
        cout << "=======Menu======" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. Size" << endl;
        cout << "5. isEmpty" << endl;
        cout << "6. isFull" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice:";
        cin >> choice;
        switch (choice) {
            case 1: if (!s.isFull()) {
                    int x;
                    cout << "enter the data: ";
                    s.enqueue((cin >> x).get());
                } else cout << "Queue is full" << endl;
                break;
            case 2: if (!s.isEmpty()) {
                    s.dequeue();
                } else cout << "Queue is empty" << endl;
                break;
            case 3: if (!s.isEmpty()) {
                    cout << s.front() << endl;
                } else cout << "Queue is empty" << endl;
                break;
            case 4: cout << s.getSize() << endl;
                break;
            case 5: cout << s.isEmpty() << endl;
                break;
            case 6: cout << s.isFull() << endl;
                break;
            case 7: cout << "Exit" << endl;
                return 0;
            default: cout << "Invalid choice" << endl;
        }
    } while (choice != 7);

    return 0;
}
