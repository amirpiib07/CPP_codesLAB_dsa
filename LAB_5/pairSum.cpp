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
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void pairSum(int target) {

        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        node* left = head;
        node* right = tail;

        int count = 0;

        cout << "Pairs with given sum:\n";

        while (left != NULL && right != NULL &&
               left != right && right->next != left) {

            int sum = left->data + right->data;

            if (sum == target) {

                cout << "(" << left->data << ", "
                     << right->data << ")" << endl;

                count++;
                left = left->next;
                right = right->prev;
            }
            else if (sum < target) {
                left = left->next;
            }
            else {
                right = right->prev;
            }
        }

        if (count == 0)
            cout << "No pair found\n";
        else
            cout << "Total pairs = " << count << endl;
    }
};

int main() {

    DoubleLL l;

    int n, data, target;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements in sorted order:\n";
    for (int i = 0; i < n; i++) {
        cin >> data;
        l.pushBack(data);
    }

    cout << "\nList: ";
    l.print();

    cout << "Enter target sum: ";
    cin >> target;

    l.pairSum(target);

    return 0;
}