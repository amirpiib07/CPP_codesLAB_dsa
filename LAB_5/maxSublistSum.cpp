#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;

    node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoubleLL {

    node* head = NULL;
    node* tail = NULL;

public:

    void pushBack(int data) {

        node* temp = new node(data);

        if (head == NULL) {
            head = tail = temp;
            return;
        }

        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }

    void print() {

        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void checkPalindrome() {

        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        node* left = head;
        node* right = tail;

        bool isPalindrome = true;

        while (left != NULL && right != NULL &&
               left != right && right->next != left) {

            if (left->data != right->data) {
                isPalindrome = false;
                break;
            }

            left = left->next;
            right = right->prev;
               }

        if (isPalindrome)
            cout << "The doubly linked list is a PALINDROME.\n";
        else
            cout << "The doubly linked list is NOT a palindrome.\n";
    }
};

int main() {

    DoubleLL l;

    int n, data;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> data;
        l.pushBack(data);
    }

    cout << "\nEntered List:\n";
    l.print();

    cout << endl;

    l.checkPalindrome();

    return 0;
}