#include <iostream>
#include <climits>
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

    void maxSublist() {

        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        int maxSum = INT_MIN;
        int currentSum = 0;

        node* temp = head;
        node* start = head;
        node* end = head;
        node* tempStart = head;

        while (temp != NULL) {

            currentSum += temp->data;

            if (currentSum > maxSum) {
                maxSum = currentSum;
                start = tempStart;
                end = temp;
            }

            if (currentSum < 0) {
                currentSum = 0;
                tempStart = temp->next;
            }

            temp = temp->next;
        }

        cout << "\nMaximum sum sublist:\n";

        node* curr = start;
        while (curr != end->next) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL\n";

        cout << "Maximum Sum = " << maxSum << endl;
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

    cout << "\nOriginal List:\n";
    l.print();

    l.maxSublist();

    return 0;
}