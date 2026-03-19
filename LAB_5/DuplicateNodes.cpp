#include <iostream>
#include <unordered_map>
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

    void deleteAllDuplicates() {

        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        unordered_map<int,int> freq;

        node* temp = head;

        // Step 1: Count frequency
        while (temp != NULL) {
            freq[temp->data]++;
            temp = temp->next;
        }

        // Step 2: Rebuild list with unique elements
        temp = head;

        node* newHead = NULL;
        node* newTail = NULL;

        while (temp != NULL) {

            if (freq[temp->data] == 1) {

                node* newNode = new node(temp->data);

                if (newHead == NULL) {
                    newHead = newTail = newNode;
                }
                else {
                    newTail->next = newNode;
                    newNode->prev = newTail;
                    newTail = newNode;
                }
            }

            temp = temp->next;
        }

        head = newHead;
        tail = newTail;
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

    l.deleteAllDuplicates();

    cout << "\nList after removing all duplicates:\n";
    l.print();

    return 0;
}