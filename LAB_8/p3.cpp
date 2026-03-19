#include <iostream>
using namespace std;

class Stack {
    int *array;
    int f;
    int r;
    int capacity;
    int size=0;
public:
    Stack(int capacity) {
        array = new int[capacity];
        this->f = 0;
        this->r = 0;
        this->size=0;
    }

    ~Stack() {
        delete[] array;
    }

    void enqueue(int x) {
        if (size!=capacity){array[(r++)%capacity] = x;size++;}
        else cout << "Queue is full" << endl;

    }

    void dequeue() {

        if (size!=0){(f++)%capacity;size--;}
        else cout << "Queue is empty" << endl;
    }

    int front() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return array[f];
    }

    int getSize() {
        return size ;
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
